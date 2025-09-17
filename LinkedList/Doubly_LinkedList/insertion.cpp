#include <iostream>
using namespace std;

// Structure for a Node in Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to print the list forward
void printListForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to print the list backward
void printListBackward(Node* tail) {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Insert at beginning
void insertAtBeginning(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        // list was empty, new node is also tail
        tail = newNode;
    }

    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        // list was empty, new node is also head
        head = newNode;
    }

    tail = newNode;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter number of nodes to create initially: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, tail, value);
    }

    cout << "Initial list forward: ";
    printListForward(head);
    cout << "Initial list backward: ";
    printListBackward(tail);

    int val;
    cout << "Enter value to insert at beginning: ";
    cin >> val;
    insertAtBeginning(head, tail, val);
    cout << "List after inserting at beginning: ";
    printListForward(head);

    cout << "Enter value to insert at end: ";
    cin >> val;
    insertAtEnd(head, tail, val);
    cout << "List after inserting at end: ";
    printListForward(head);

    return 0;
}
