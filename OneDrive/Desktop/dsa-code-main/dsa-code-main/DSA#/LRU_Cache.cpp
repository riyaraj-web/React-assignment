// 🧠 DSA Problem: LRU Cache Implementation
// 📁 Folder: DSA/Design/
// 🧑 Author: Aditya
// 📝 Description:
// Implement a Least Recently Used (LRU) Cache using
// HashMap + Doubly Linked List for O(1) get() and put() operations.

#include <bits/stdc++.h>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Helper to add a node right after the head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper to remove a node
    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // Move a node to the front (most recently used)
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Pop least recently used (tail->prev)
    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addNode(node);

            if (cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }

    // Optional: Print cache state (for debugging)
    void printCache() {
        Node* curr = head->next;
        cout << "Cache state (MRU -> LRU): ";
        while (curr != tail) {
            cout << "[" << curr->key << ":" << curr->value << "] ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// 🧪 Example test
int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // -1
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4
}
