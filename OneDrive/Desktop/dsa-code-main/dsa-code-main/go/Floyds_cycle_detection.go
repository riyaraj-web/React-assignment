#given the head of a linked list,determine if it contains a cycle.
package main

import "fmt"

type ListNode struct {
    Val  int
    Next *ListNode
}

func hasCycle(head *ListNode) bool {
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
        if slow == fast {
            return true
        }
    }
    return false
}

func main() {
    // Creating a cycle for testing
    n1 := &ListNode{1, nil}
    n2 := &ListNode{2, nil}
    n3 := &ListNode{3, nil}
    n4 := &ListNode{4, nil}
    n1.Next = n2
    n2.Next = n3
    n3.Next = n4
    n4.Next = n2 // creates a cycle

    fmt.Println("Has Cycle?", hasCycle(n1))
}