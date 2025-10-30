import java.util.LinkedList;

public class TodoList {
    private LinkedList<Task> tasks;

    public TodoList() {
        tasks = new LinkedList<>();
    }

    // Add task
    public void addTask(String description) {
        tasks.add(new Task(description));
    }

    // Mark a task done
    public void markTaskDone(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.get(index).markDone();
        }
    }

    // Remove a task
    public void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.remove(index);
        }
    }

    // Display the list
    public void displayTasks() {
        for (int i = 0; i < tasks.size(); i++) {
            Task task = tasks.get(i);
            String status = task.isDone() ? "[Done]" : "[Pending]";
            System.out.println(i + " - " + status + " " + task.getDescription());
        }
    }

}
