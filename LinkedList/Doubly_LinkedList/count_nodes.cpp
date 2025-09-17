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

// Function to count nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
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
        insertAtEnd(head, tail, value);
    }

    cout << "Current list: ";
    printList(head);
    cout << "Total nodes in the list: " << countNodes(head) << endl;
    return 0;
}
