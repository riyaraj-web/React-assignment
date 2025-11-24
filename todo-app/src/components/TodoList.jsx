import React from 'react';
import { Check } from 'lucide-react';
import TodoItem from './TodoItem';

const TodoList = ({ todos, onEdit, onDelete, onToggle, onDragStart, onDragOver }) => {
  if (!todos || todos.length === 0) {
    return (
      <div className="text-center py-16 bg-gradient-to-br from-white to-blue-50 dark:from-gray-800 dark:to-blue-900/20 rounded-2xl shadow-2xl transition-all border-2 border-dashed border-blue-200 dark:border-blue-700">
        <div className="text-blue-400 dark:text-blue-500 mb-4 animate-bounce">
          <Check size={80} className="mx-auto" />
        </div>
        <h3 className="text-2xl font-bold text-gray-700 dark:text-gray-200 mb-3">No tasks yet! 🎯</h3>
        <p className="text-gray-500 dark:text-gray-400 text-lg">Add your first task to get started on your productivity journey!</p>
      </div>
    );
  }

  const activeTasks = todos.filter(t => !t.completed);
  const completedTasks = todos.filter(t => t.completed);

  return (
    <div className="space-y-8">
      {activeTasks.length > 0 && (
        <div>
          <div className="flex items-center gap-3 mb-4">
            <div className="h-1 flex-1 bg-gradient-to-r from-blue-500 to-purple-500 rounded-full"></div>
            <h3 className="text-xl font-bold text-gray-700 dark:text-gray-200 flex items-center gap-2">
              <span className="bg-gradient-to-r from-blue-600 to-purple-600 text-white px-4 py-2 rounded-full shadow-lg">
                ⚡ Active Tasks ({activeTasks.length})
              </span>
            </h3>
            <div className="h-1 flex-1 bg-gradient-to-l from-blue-500 to-purple-500 rounded-full"></div>
          </div>
          {activeTasks.map((todo, index) => (
            <div
              key={todo.id}
              draggable
              onDragStart={(e) => onDragStart(e, todos.indexOf(todo))}
              onDragOver={(e) => onDragOver(e, todos.indexOf(todo))}
              className="cursor-move"
            >
              <TodoItem
                todo={todo}
                onEdit={onEdit}
                onDelete={onDelete}
                onToggle={onToggle}
              />
            </div>
          ))}
        </div>
      )}

      {completedTasks.length > 0 && (
        <div>
          <div className="flex items-center gap-3 mb-4">
            <div className="h-1 flex-1 bg-gradient-to-r from-green-500 to-emerald-500 rounded-full"></div>
            <h3 className="text-xl font-bold text-gray-700 dark:text-gray-200 flex items-center gap-2">
              <span className="bg-gradient-to-r from-green-600 to-emerald-600 text-white px-4 py-2 rounded-full shadow-lg">
                ✅ Completed ({completedTasks.length})
              </span>
            </h3>
            <div className="h-1 flex-1 bg-gradient-to-l from-green-500 to-emerald-500 rounded-full"></div>
          </div>
          {completedTasks.map((todo, index) => (
            <div
              key={todo.id}
              draggable
              onDragStart={(e) => onDragStart(e, todos.indexOf(todo))}
              onDragOver={(e) => onDragOver(e, todos.indexOf(todo))}
              className="cursor-move"
            >
              <TodoItem
                todo={todo}
                onEdit={onEdit}
                onDelete={onDelete}
                onToggle={onToggle}
              />
            </div>
          ))}
        </div>
      )}
    </div>
  );
};

export default TodoList;