#include <iostream>
using namespace std;

// Structure for a Node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to print all elements of the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert new node at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node;   // create new node
    newNode->data = value;      // put data
    newNode->next = head;       // next of new node is old head
    head = newNode;             // move head to new node
}

// Insert new node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;   // create new node
    newNode->data = value;      // put data
    newNode->next = nullptr;    // last node will point to NULL

    // if list is empty, new node becomes head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // otherwise move to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;  // link last node to new node
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter number of initial nodes: ";
    cin >> n;

    // create list by inserting nodes at the end
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Initial List: ";
    printList(head);

    // insert at beginning
    int val;
    cout << "Enter value to insert at beginning: ";
    cin >> val;
    insertAtBeginning(head, val);

    cout << "List after inserting at beginning: ";
    printList(head);

    // insert at end
    cout << "Enter value to insert at end: ";
    cin >> val;
    insertAtEnd(head, val);

    cout << "List after inserting at end: ";
    printList(head);

    return 0;
}
