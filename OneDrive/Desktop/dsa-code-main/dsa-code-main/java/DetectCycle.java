// Definition for singly-linked list
class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class DetectCycle {

    // Function to detect cycle in a linked list
    public static boolean hasCycle(ListNode head) {
        if (head == null) return false;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;        // move slow by 1
            fast = fast.next.next;   // move fast by 2

            if (slow == fast) {      // cycle detected
                return true;
            }
        }

        return false; // no cycle
    }

    public static void main(String[] args) {
        // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        boolean result = hasCycle(head);
        System.out.println(result ? "Cycle detected." : "No cycle.");
    }
}
