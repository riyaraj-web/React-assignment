// AddTwoNumbers

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        
        return dummy->next;
    }
};

ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);
    
    cout << "L1: "; printList(l1);
    cout << "L2: "; printList(l2);
    
    ListNode* result = sol.addTwoNumbers(l1, l2);
    cout << "Result: "; printList(result);
    
    return 0;
}