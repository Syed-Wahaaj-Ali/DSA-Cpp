#include <iostream>
using namespace std;

// Structure for a Node
struct Node {
    int data;      // data part of node
    Node* next;    // pointer to next node
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;     // will store previous node
    Node* current = head;     // start with head
    Node* next = nullptr;     // to temporarily store next node

    // Traverse the list and reverse links
    while (current != nullptr) {
        next = current->next;     // save next node
        current->next = prev;     // reverse the link
        prev = current;           // move prev forward
        current = next;           // move current forward
    }

    // After loop, prev becomes new head
    head = prev;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    // create linked list
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        // create new node
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        // if list is empty, make it head
        if (head == nullptr) {
            head = newNode;
        } 
        else {
            // otherwise insert at end
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Original List: ";
    printList(head);

    // reverse the list
    reverseList(head);

    cout << "Reversed List: ";
    printList(head);
    return 0;
}
