import { useState, useEffect } from 'react';
import { io } from 'socket.io-client';
import TodoForm from './components/TodoForm';
import TodoList from './components/TodoList';
import './App.css';


const socket = io('http://localhost:3000', {
  transports: ['websocket', 'polling'],
  reconnection: true,
  reconnectionDelay: 1000,
  reconnectionAttempts: 5
});

const App = () => {
  const [todos, setTodos] = useState([]);
  const [editingId, setEditingId] = useState(null);
  const [filter, setFilter] = useState('all');
  const [searchQuery, setSearchQuery] = useState('');
  const [sortBy, setSortBy] = useState('default');
  const [darkMode, setDarkMode] = useState(false);
  const [isConnected, setIsConnected] = useState(false);

  
  useEffect(() => {
    const savedTodos = localStorage.getItem('todos');
    if (savedTodos) {
      try {
        setTodos(JSON.parse(savedTodos));
      } catch (error) {
        console.error('Error loading todos from localStorage:', error);
      }
    }
  }, []);

   
  useEffect(() => {
    localStorage.setItem('todos', JSON.stringify(todos));
  }, [todos]);

   
  useEffect(() => {
    socket.on('connect', () => {
      console.log('Connected to server');
      setIsConnected(true);
      socket.emit('todos:sync', todos);
    });

    socket.on('disconnect', () => {
      console.log('Disconnected from server');
      setIsConnected(false);
    });

    socket.on('todos:load', (initialTodos) => {
      setTodos(initialTodos);
    });

    socket.on('todo:created', (newTodo) => {
      setTodos((prev) => {
        if (!prev.find(t => t.id === newTodo.id)) {
          return [...prev, newTodo];
        }
        return prev;
      });
    });

    socket.on('todo:updated', (updatedTodo) => {
      setTodos((prev) =>
        prev.map((todo) => (todo.id === updatedTodo.id ? updatedTodo : todo))
      );
    });

    socket.on('todo:deleted', (todoId) => {
      setTodos((prev) => prev.filter((todo) => todo.id !== todoId));
    });

    socket.on('todo:toggled', (toggledTodo) => {
      setTodos((prev) =>
        prev.map((todo) => (todo.id === toggledTodo.id ? toggledTodo : todo))
      );
    });

    return () => {
      socket.off('connect');
      socket.off('disconnect');
      socket.off('todos:load');
      socket.off('todo:created');
      socket.off('todo:updated');
      socket.off('todo:deleted');
      socket.off('todo:toggled');
    };
  }, []);

   
  useEffect(() => {
    if (darkMode) {
      document.body.classList.add('dark-mode');
    } else {
      document.body.classList.remove('dark-mode');
    }
  }, [darkMode]);

   
  const handleAddTask = (taskData) => {
    if (!taskData.task.trim()) {
      alert('Task name cannot be empty');
      return;
    }

    const newTodo = {
      id: Date.now(),
      task: taskData.task.trim(),
      dueDate: taskData.dueDate || null,
      priority: taskData.priority || 'medium',
      completed: false,
      createdAt: new Date().toISOString()
    };

    setTodos([...todos, newTodo]);
    socket.emit('todo:create', newTodo);
  };

 
  const handleUpdateTask = (taskData) => {
    if (!taskData.task.trim()) {
      alert('Task name cannot be empty');
      return;
    }

    const updatedTodos = todos.map((todo) =>
      todo.id === editingId
        ? { ...todo, task: taskData.task.trim(), dueDate: taskData.dueDate, priority: taskData.priority }
        : todo
    );

    setTodos(updatedTodos);
    const updatedTodo = updatedTodos.find(t => t.id === editingId);
    socket.emit('todo:update', updatedTodo);
    setEditingId(null);
  };

   
  const handleDelete = (id) => {
    setTodos(todos.filter((todo) => todo.id !== id));
    socket.emit('todo:delete', id);
  };

   
  const handleToggle = (id) => {
    const updatedTodos = todos.map((todo) =>
      todo.id === id ? { ...todo, completed: !todo.completed } : todo
    );
    setTodos(updatedTodos);
    const toggledTodo = updatedTodos.find(t => t.id === id);
    socket.emit('todo:toggle', toggledTodo);
  };

  
  const handleEdit = (id) => {
    setEditingId(id);
  };

   
  const handleCancelEdit = () => {
    setEditingId(null);
  };

   
  const getFilteredTodos = () => {
    let filtered = [...todos];

     
    if (filter === 'active') {
      filtered = filtered.filter((todo) => !todo.completed);
    } else if (filter === 'completed') {
      filtered = filtered.filter((todo) => todo.completed);
    } else if (filter === 'low' || filter === 'medium' || filter === 'high') {
      filtered = filtered.filter((todo) => todo.priority === filter);
    }

     
    if (searchQuery) {
      filtered = filtered.filter((todo) =>
        todo.task.toLowerCase().includes(searchQuery.toLowerCase())
      );
    }

    
    if (sortBy === 'priority') {
      const priorityOrder = { high: 1, medium: 2, low: 3 };
      filtered.sort((a, b) => priorityOrder[a.priority] - priorityOrder[b.priority]);
    } else if (sortBy === 'dueDate') {
      filtered.sort((a, b) => {
        if (!a.dueDate) return 1;
        if (!b.dueDate) return -1;
        return new Date(a.dueDate) - new Date(b.dueDate);
      });
    }

    return filtered;
  };

  const editingTodo = todos.find((todo) => todo.id === editingId);

  return (
    <div className={`app-container ${darkMode ? 'dark' : ''}`}>
      <div className="todo-card">
        {/* Header */}
        <div className="header">
          <div className="header-content">
            <div className="header-icon">📋</div>
            <h1>Todo List</h1>
            <p className="subtitle">Stay organized and productive ⭐</p>
          </div>
          <button
            className="dark-mode-toggle"
            onClick={() => setDarkMode(!darkMode)}
            title="Toggle dark mode"
          >
            {darkMode ? '☀️' : '🌙'}
          </button>
        </div>

        {/* Filters Bar */}
        <div className="filters-bar">
          <div className="filter-buttons">
            <button
              className={filter === 'all' ? 'filter-btn active' : 'filter-btn'}
              onClick={() => setFilter('all')}
            >
              All
            </button>
            <button
              className={filter === 'active' ? 'filter-btn active' : 'filter-btn'}
              onClick={() => setFilter('active')}
            >
              Active
            </button>
            <button
              className={filter === 'completed' ? 'filter-btn active' : 'filter-btn'}
              onClick={() => setFilter('completed')}
            >
              Completed
            </button>
          </div>

          <div className="filter-controls">
            <select
              value={filter.match(/^(low|medium|high)$/) ? filter : ''}
              onChange={(e) => setFilter(e.target.value || 'all')}
              className="priority-filter"
            >
              <option value="">🍀 Priority</option>
              <option value="low">Low</option>
              <option value="medium">Medium</option>
              <option value="high">High</option>
            </select>

            <select
              value={sortBy}
              onChange={(e) => setSortBy(e.target.value)}
              className="sort-select"
            >
              <option value="default">⚡ Sort by</option>
              <option value="priority">Priority</option>
              <option value="dueDate">Due Date</option>
            </select>
          </div>
        </div>

        {/* Search Bar */}
        <div className="search-bar">
          <span className="search-icon">🔍</span>
          <input
            type="text"
            placeholder="Search tasks..."
            value={searchQuery}
            onChange={(e) => setSearchQuery(e.target.value)}
            className="search-input"
          />
        </div>

        {/* Add/Edit Task Form */}
        <TodoForm
          onSubmit={editingId ? handleUpdateTask : handleAddTask}
          editingTodo={editingTodo}
          onCancel={handleCancelEdit}
          isEditing={!!editingId}
        />

        {/* Task List */}
        <TodoList
          todos={getFilteredTodos()}
          onToggle={handleToggle}
          onDelete={handleDelete}
          onEdit={handleEdit}
        />

        {/* Real-time Sync Status (Bonus Feature) */}
        {isConnected && (
          <div className="sync-status">
            🟢 Real-time sync active
          </div>
        )}
      </div>
    </div>
  );
};

export default App;