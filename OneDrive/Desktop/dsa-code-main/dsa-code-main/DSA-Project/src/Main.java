import java.util.Scanner;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        TodoList todo=new TodoList();
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1. Add Task\n2. Mark Done\n3. Remove Task\n4. Display Tasks\n0. Exit");
            choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter task description: ");
                    String desc = sc.nextLine();
                    todo.addTask(desc);
                    break;
                case 2:
                    System.out.print("Enter task number to mark done: ");
                    int doneIndex = sc.nextInt();
                    todo.markTaskDone(doneIndex);
                    break;
                case 3:
                    System.out.print("Enter task number to remove: ");
                    int remIndex = sc.nextInt();
                    todo.removeTask(remIndex);
                    break;
                case 4:
                    todo.displayTasks();
                    break;
                case 0:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid option.");
            }
        } while (choice != 0);

        sc.close();
    }
}