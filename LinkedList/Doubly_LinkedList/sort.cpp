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

// Function to sort doubly linked list using bubble sort
void sortList(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    Node* temp;
    Node* last = nullptr;

    do {
        swapped = false;
        temp = head;

        while (temp->next != last) {
            if (temp->data > temp->next->data) {
                // swap data
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swapped = true;
            }
            temp = temp->next;
        }
        last = temp; // last sorted node
    } while (swapped);
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
    cout << "Original list: ";
    printList(head);
    sortList(head);
    cout << "Sorted list: ";
    printList(head);
    return 0;
}
