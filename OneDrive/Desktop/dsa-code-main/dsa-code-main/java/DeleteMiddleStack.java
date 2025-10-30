import java.util.*;

/**
 * Delete Middle Element from Stack - Recursive Approach
 * Remove middle element without using additional data structure.
 */
public class DeleteMiddleStack {
    
    // Delete middle element using recursion
    public void deleteMiddle(Stack<Integer> stack) {
        int size = stack.size();
        int middle = size / 2;
        deleteMiddleHelper(stack, middle);
    }
    
    private void deleteMiddleHelper(Stack<Integer> stack, int index) {
        if (index == 0) {
            stack.pop(); // Remove middle element
            return;
        }
        
        int temp = stack.pop();
        deleteMiddleHelper(stack, index - 1);
        stack.push(temp);
    }
    
    public static void main(String[] args) {
        DeleteMiddleStack solution = new DeleteMiddleStack();
        
        // Test case 1
        Stack<Integer> stack1 = new Stack<>();
        stack1.addAll(Arrays.asList(10, 20, 30, 40, 50));
        System.out.println("Original: " + stack1);
        solution.deleteMiddle(stack1);
        System.out.println("After deletion: " + stack1); // [10, 20, 40, 50]
        
        // Test case 2
        Stack<Integer> stack2 = new Stack<>();
        stack2.addAll(Arrays.asList(5, 8, 6, 7, 6, 6, 5, 10, 12, 9));
        System.out.println("\nOriginal: " + stack2);
        solution.deleteMiddle(stack2);
        System.out.println("After deletion: " + stack2); // [5, 8, 6, 7, 6, 5, 10, 12, 9]
    }
}