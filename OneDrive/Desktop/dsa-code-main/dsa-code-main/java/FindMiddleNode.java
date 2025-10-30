// Definition for singly-linked list
class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class FindMiddleNode {

    // Function to find the middle node
    public static ListNode findMiddle(ListNode head) {
        if (head == null) return null;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;        // move slow by 1
            fast = fast.next.next;   // move fast by 2
        }

        return slow; // slow is now at the middle
    }

    public static void main(String[] args) {
        // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        ListNode middle = findMiddle(head);
        if (middle != null) {
            System.out.println("Middle node value: " + middle.val);
        } else {
            System.out.println("The list is empty.");
        }
    }
}
