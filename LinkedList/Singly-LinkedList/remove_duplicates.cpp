#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeDuplicates(Node* head) {
    Node* current = head;

    // Go through each node
    while (current != nullptr) {
        Node* runner = current;
        // Compare current node with rest of the list
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                // Duplicate found → delete it
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    // Create list with user input
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);
    removeDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);
    return 0;
}
