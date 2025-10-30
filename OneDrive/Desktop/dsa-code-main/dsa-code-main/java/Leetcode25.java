// File: Leetcode25.java

public class Leetcode25 {

    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) {
            return null;
        }

        // Check if there are at least k nodes left to reverse
        ListNode temp = head;
        int count = 0;
        while (temp != null && count < k) {
            temp = temp.next;
            count++;
        }

        // If we have fewer than k nodes, return head as is
        if (count < k) {
            return head;
        }

        // Reverse first k nodes
        ListNode curr = head, prev = null, next = null;
        count = 0;
        while (curr != null && count < k) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse the remaining nodes
        if (next != null) {
            head.next = reverseKGroup(next, k);
        }

        return prev;
    }

    // --- MAIN METHOD TO TEST ---
    public static void main(String[] args) {
        // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        int k = 2; // Group size

        Leetcode25 solution = new Leetcode25();
        ListNode result = solution.reverseKGroup(head, k);

        // Print reversed list
        System.out.print("Reversed in groups of " + k + ": ");
        printList(result);
    }

    // Helper function to print the linked list
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }
}

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}
