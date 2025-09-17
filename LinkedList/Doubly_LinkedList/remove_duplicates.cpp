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

// Function to remove duplicates
void removeDuplicates(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current->next;

        while (temp != nullptr) {
            if (temp->data == current->data) {
                Node* nodeToDelete = temp;
                temp = temp->next;

                // unlink the node
                if (nodeToDelete->prev != nullptr) {
                    nodeToDelete->prev->next = nodeToDelete->next;
                }
                if (nodeToDelete->next != nullptr) {
                    nodeToDelete->next->prev = nodeToDelete->prev;
                }

                delete nodeToDelete;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
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
        insertAtEnd(head, tail, value);
    }

    cout << "Original list: ";
    printList(head);
    removeDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);
    return 0;
}
