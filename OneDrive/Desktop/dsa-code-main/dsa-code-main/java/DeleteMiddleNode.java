// Definition for singly-linked list
class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class DeleteMiddleNode {

    // Function to delete the middle node
    public static ListNode deleteMiddle(ListNode head) {
        if (head == null || head.next == null) {
            return null; // if list has 0 or 1 node, result is empty
        }

        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null; // to keep track of node before slow

        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            prev = slow;
            slow = slow.next;
        }

        // delete the middle node
        prev.next = slow.next;
        return head;
    }

    // Helper function to print the linked list
    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.println("Original list:");
        printList(head);

        head = deleteMiddle(head);

        System.out.println("After deleting middle node:");
        printList(head);
    }
}
