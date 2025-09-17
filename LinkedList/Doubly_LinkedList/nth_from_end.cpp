#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert node at end
void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode; // list was empty
    }
    tail = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find Nth node from end
void findNthFromEnd(Node* tail, int n) {
    Node* temp = tail;
    int count = 1;

    while (temp != nullptr && count < n) {
        temp = temp->prev;
        count++;
    }

    if (temp == nullptr) {
        cout << "There are less than " << n << " nodes in the list." << endl;
    } else {
        cout << n << "-th node from the end is: " << temp->data << endl;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int nNodes, value, n;

    cout << "Enter number of nodes: ";
    cin >> nNodes;

    for (int i = 0; i < nNodes; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, tail, value);
    }

    cout << "Current list: ";
    printList(head);
    cout << "Enter N to find N-th node from the end: ";
    cin >> n;
    findNthFromEnd(tail, n);
    return 0;
}
