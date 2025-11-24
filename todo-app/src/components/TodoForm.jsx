import React, { useState, useEffect } from 'react';
import { Check, X, Plus } from 'lucide-react';

const TodoForm = ({ editingTask, onSave, onCancel }) => {
  const [task, setTask] = useState('');
  const [dueDate, setDueDate] = useState('');
  const [priority, setPriority] = useState('Low');

  useEffect(() => {
    if (editingTask) {
      setTask(editingTask.task || '');
      setDueDate(editingTask.dueDate || '');
      setPriority(editingTask.priority || 'Low');
    }
  }, [editingTask]);

  const handleSubmit = (e) => {
    e.preventDefault();
    if (task.trim() === '') {
      alert('Task name cannot be empty');
      return;
    }

    // Validate past due dates
    if (dueDate) {
      const selectedDate = new Date(dueDate);
      const today = new Date();
      today.setHours(0, 0, 0, 0); // Reset time to compare only dates
      
      if (selectedDate < today) {
        const confirmPastDate = window.confirm(
          'The due date is in the past. Are you sure you want to continue?'
        );
        if (!confirmPastDate) {
          return;
        }
      }
    }

    onSave({ task: task.trim(), dueDate, priority });
    setTask('');
    setDueDate('');
    setPriority('Low');
  };

  const handleCancel = () => {
    setTask('');
    setDueDate('');
    setPriority('Low');
    onCancel();
  };

  return (
    <div className="bg-white dark:bg-gray-800 rounded-lg shadow-md p-6 mb-6 transition-colors duration-200">
      <h2 className="text-xl font-bold mb-4 text-gray-800 dark:text-white">
        {editingTask ? 'Edit Task' : 'Add New Task'}
      </h2>

      <form onSubmit={handleSubmit}>
        <div className="mb-4">
          <label className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">
            Task Name
          </label>
          <input
            type="text"
            value={task}
            onChange={(e) => setTask(e.target.value)}
            placeholder="Enter task name..."
            className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-lg bg-white dark:bg-gray-700 text-gray-900 dark:text-white placeholder-gray-400 dark:placeholder-gray-500 focus:ring-2 focus:ring-blue-500 focus:border-transparent outline-none transition-colors"
          />
        </div>

        <div className="mb-4">
          <label className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">
            Due Date
          </label>
          <input
            type="date"
            value={dueDate}
            onChange={(e) => setDueDate(e.target.value)}
            className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-lg bg-white dark:bg-gray-700 text-gray-900 dark:text-white focus:ring-2 focus:ring-blue-500 focus:border-transparent outline-none transition-colors"
          />
        </div>

        <div className="mb-4">
          <label className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-2">
            Priority
          </label>
          <select
            value={priority}
            onChange={(e) => setPriority(e.target.value)}
            className="w-full px-4 py-2 border border-gray-300 dark:border-gray-600 rounded-lg bg-white dark:bg-gray-700 text-gray-900 dark:text-white focus:ring-2 focus:ring-blue-500 focus:border-transparent outline-none transition-colors"
          >
            <option value="Low">Low</option>
            <option value="Medium">Medium</option>
            <option value="High">High</option>
          </select>
        </div>

        <div className="flex gap-2">
          <button
            type="submit"
            className="flex-1 bg-blue-600 hover:bg-blue-700 text-white font-medium py-2 px-4 rounded-lg transition-colors flex items-center justify-center gap-2"
          >
            {editingTask ? <Check size={18} /> : <Plus size={18} />}
            {editingTask ? 'Update Task' : 'Add Task'}
          </button>

          {editingTask && (
            <button
              type="button"
              onClick={handleCancel}
              className="bg-gray-400 hover:bg-gray-500 dark:bg-gray-600 dark:hover:bg-gray-700 text-white font-medium py-2 px-4 rounded-lg transition-colors flex items-center gap-2"
            >
              <X size={18} />
              Cancel
            </button>
          )}
        </div>
      </form>
    </div>
  );
};

export default TodoForm;