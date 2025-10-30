struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

//Detect Cycle in Linked List (Floyd’s Algorithm)
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
//Detect Cycle & Remove Cycle (Floyd’s Algorithm, Singly)
bool detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void removeCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    do {
        if (!fast || !fast->next) return;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = nullptr;
}
