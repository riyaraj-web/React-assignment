#include <iostream>
#include <vector>
using namespace std;

//Delete all occurances of a key in dll


struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
        prev = nullptr;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};


class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
 if (!head) return nullptr;
ListNode* temp = head;

while(temp!=nullptr){

    ListNode* front=temp->next;
if(temp->val==target){
    if(temp==head){
        head=head->next;
        if(head) head->prev=nullptr;
    }else{
        if(temp->prev) temp->prev->next=temp->next;
        if(temp->next) temp->next->prev=temp->prev;
    }
    delete temp;
    }
    temp=front;
}
return head;
    }
};

// Find Pairs with Given Sum in Doubly Linked List


class Solution2 {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
    vector<vector<int>> result;
    if(!head) return result;
    ListNode* left=head;
    ListNode* right=head;
    while(right->next!=nullptr){
right=right->next;
    }
      while(left!=nullptr && right!=nullptr && left!=right && right->next!=left){
        int sum=left->val+right->val;
        if(sum==target){
            result.push_back({left->val,right->val});
left=left->next;
right=right->prev;
        }else if(sum<target){
            left=left->next;
        }else{
            right=right->prev;
        }
      }  
      return result;
    }
};

// Remove duplicated from sorted DLL
class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
if(head==nullptr || head->next==nullptr){
    return head;
}

ListNode* temp=head;

while(temp!=nullptr && temp->next!=nullptr){
    
        if(temp->val==temp->next->val){
            ListNode* dup=temp->next;
            temp->next = dup->next;

if(dup->next!=nullptr)
dup->next->prev=temp;
delete dup;
        }else{
            temp=temp->next;
        }
}
return head;
    }
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while (true) {
           
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) break; 

    
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};
// Merge k Sorted Lists
#include <queue>
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;
            if (curr->next) pq.push(curr->next);
        }

        return dummy->next;
    }
};
