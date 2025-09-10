#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // pointer to next node
};

int main() {
    Node* head = nullptr;   // start with empty list
    Node* temp = nullptr;   // helper pointer
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        // create new node
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode; // first node becomes head
            temp = head;
        } else {
            temp->next = newNode; // link new node
            temp = newNode;       // move temp to last node
        }
    }

    // print linked list
    cout << "Linked List: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
