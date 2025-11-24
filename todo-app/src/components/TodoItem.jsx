import React from 'react';
import { Trash2, Edit2, Calendar, GripVertical } from 'lucide-react';

const TodoItem = ({ todo, onEdit, onDelete, onToggle }) => {
  const formatDate = (dateString) => {
    if (!dateString) return 'No due date';
    const date = new Date(dateString);
    return date.toLocaleDateString('en-US', { month: 'short', day: 'numeric', year: 'numeric' });
  };

  const isOverdue = () => {
    if (!todo.dueDate || todo.completed) return false;
    return new Date(todo.dueDate) < new Date();
  };

  const priorityColor = todo.priority === 'High' 
    ? 'bg-red-100 text-red-800 dark:bg-red-900 dark:text-red-200' 
    : todo.priority === 'Medium' 
    ? 'bg-amber-100 text-amber-800 dark:bg-amber-900 dark:text-amber-200' 
    : 'bg-gray-100 text-gray-800 dark:bg-gray-700 dark:text-gray-300';

  return (
    <div className={`bg-white dark:bg-gray-800 rounded-lg shadow-md p-4 mb-3 border-l-4 transition-colors hover:shadow-lg ${
      todo.completed ? 'border-green-500 dark:border-green-400' : isOverdue() ? 'border-red-500 dark:border-red-400' : 'border-blue-500 dark:border-blue-400'
    }`}>
      <div className="flex items-start gap-3">
        <div className="text-gray-400 dark:text-gray-500 cursor-move mt-1">
          <GripVertical size={20} />
        </div>
        
        <input
          type="checkbox"
          checked={todo.completed}
          onChange={() => onToggle(todo.id)}
          className="mt-1 w-5 h-5 text-blue-600 dark:text-blue-500 rounded focus:ring-2 focus:ring-blue-500 dark:focus:ring-blue-400 bg-white dark:bg-gray-700 border-gray-300 dark:border-gray-600"
        />

        <div className="flex-1">
          <h3 className={`text-lg font-medium transition-colors ${
            todo.completed ? 'line-through text-gray-500 dark:text-gray-400' : 'text-gray-800 dark:text-white'
          }`}>
            {todo.task}
          </h3>

          <div className="mt-2 flex items-center gap-2">
            <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium transition-colors ${priorityColor}`}>
              {todo.priority || 'Low'}
            </span>
          </div>

          {todo.dueDate && (
            <div className={`flex items-center gap-1 text-sm mt-1 transition-colors ${
              isOverdue() ? 'text-red-600 dark:text-red-400 font-medium' : 'text-gray-600 dark:text-gray-400'
            }`}>
              <Calendar size={14} />
              {formatDate(todo.dueDate)}
              {isOverdue() && ' (Overdue)'}
            </div>
          )}
        </div>

        <div className="flex gap-2">
          <button
            onClick={() => onEdit(todo)}
            className="p-2 text-blue-600 dark:text-blue-400 hover:bg-blue-50 dark:hover:bg-blue-900/30 rounded-lg transition-colors"
            title="Edit task"
          >
            <Edit2 size={18} />
          </button>
          <button
            onClick={() => onDelete(todo.id)}
            className="p-2 text-red-600 dark:text-red-400 hover:bg-red-50 dark:hover:bg-red-900/30 rounded-lg transition-colors"
            title="Delete task"
          >
            <Trash2 size={18} />
          </button>
        </div>
      </div>
    </div>
  );
};

export default TodoItem;