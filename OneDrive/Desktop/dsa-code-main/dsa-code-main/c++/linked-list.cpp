#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node* getNode() {
    struct node* q = (struct node*)malloc(sizeof(struct node));
    q->next = NULL;
    return q;
}

// Insert at Beginning
struct node* InsertAtBegin(struct node* start, int value) {
    struct node* newnode = getNode();
    newnode->data = value;
    newnode->next = start;
    start = newnode;
    return start;
}

// Traversal
void Traversal(struct node* start) {
    struct node* p = start;
    if (p == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Insert After a Node (by data value)
struct node* InsertAfter(struct node* start, int value, int pos) {
    struct node* temp = start;
    while (temp != NULL && temp->data != pos) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position not found!" << endl;
        return start;
    }
    struct node* p = getNode();
    p->data = value;
    p->next = temp->next;
    temp->next = p;
    return start;
}

// Insert at End
struct node* InsertAtEnd(struct node* start, int value) {
    struct node* newnode = getNode();
    newnode->data = value;

    if (start == NULL) {
        start = newnode;
        return start;
    }

    struct node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return start;
}

// Delete from Start
struct node* DeleteFromStart(struct node* start) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return start;
    }
    struct node* temp = start;
    start = start->next;
    free(temp);
    return start;
}

// Delete from End
struct node* DeleteFromEnd(struct node* start) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return start;
    }
    if (start->next == NULL) {
        free(start);
        return NULL;
    }
    struct node* temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return start;
}

// Delete After a Node
struct node* DeleteAfter(struct node* start, int pos) {
    struct node* temp = start;
    while (temp != NULL && temp->data != pos) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Position not found or no node exists after it!" << endl;
        return start;
    }
    struct node* p = temp->next;
    temp->next = p->next;
    free(p);
    return start;
}

int main() {
    int ch;
    do {
        cout << "\nEnter your choice\n";
        cout << "1. Traversal\n";
        cout << "2. Insertion from the beginning\n";
        cout << "3. Insertion after a node\n";
        cout << "4. Insertion at the end\n";
        cout << "5. Deletion from start\n";
        cout << "6. Deletion from the end\n";
        cout << "7. Deletion after a node\n";
        cout << "0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                Traversal(start);
                break;
            case 2: {
                int value;
                cout << "Enter the value to be inserted: ";
                cin >> value;
                start = InsertAtBegin(start, value);
                break;
            }
            case 3: {
                int value, pos;
                cout << "Enter the value to be inserted: ";
                cin >> value;
                cout << "Enter the position (node value) after which to insert: ";
                cin >> pos;
                start = InsertAfter(start, value, pos);
                break;
            }
            case 4: {
                int value;
                cout << "Enter the value to be inserted: ";
                cin >> value;
                start = InsertAtEnd(start, value);
                break;
            }
            case 5:
                start = DeleteFromStart(start);
                break;
            case 6:
                start = DeleteFromEnd(start);
                break;
            case 7: {
                int pos;
                cout << "Enter the node value after which to delete: ";
                cin >> pos;
                start = DeleteAfter(start, pos);
                break;
            }
            case 0:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (ch != 0);

    return 0;
}
