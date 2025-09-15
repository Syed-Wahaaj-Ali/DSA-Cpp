#include <iostream>
using namespace std;

// Structure for a Node
struct Node {
    int data;
    Node* next;
};

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find Nth node from the end
void nthFromEnd(Node* head, int n) {
    Node* first = head;
    Node* second = head;

    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == nullptr) {
            cout << "List has fewer than " << n << " nodes." << endl;
            return;
        }
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    cout << "The " << n << "th node from the end is: " << second->data << endl;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    // create list
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Linked List: ";
    printList(head);

    int pos;
    cout << "Enter position from end to find: ";
    cin >> pos;

    nthFromEnd(head, pos);

    return 0;
}
