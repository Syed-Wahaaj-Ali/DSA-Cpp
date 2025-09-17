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

// Function to search for a value in the list
void searchNode(Node* head, int value) {
    Node* temp = head;
    int pos = 1;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << "." << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        cout << "Value " << value << " not found in the list." << endl;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, value;

    cout << "Enter number of nodes to create initially: ";
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

    cout << "Current list: ";
    printList(head);

    cout << "Enter value to search: ";
    cin >> value;
    searchNode(head, value);
    return 0;
}
