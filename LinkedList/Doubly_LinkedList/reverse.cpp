#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the doubly linked list
void reverseList(Node*& head, Node*& tail) {
    Node* current = head;
    Node* temp = nullptr;

    // swap next and prev for all nodes
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // move to next node (was prev)
    }

    // swap head and tail
    if (temp != nullptr) {
        tail = head;
        head = temp->prev;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        // insert at end
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    cout << "Original list: ";
    printList(head);
    reverseList(head, tail);
    cout << "Reversed list: ";
    printList(head);
    return 0;
}
