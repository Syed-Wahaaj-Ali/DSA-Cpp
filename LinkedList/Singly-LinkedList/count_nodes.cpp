#include <iostream>
using namespace std;

// Structure for a Node
struct Node {
    int data;
    Node* next;
};

// Function to count total nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to print the list
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

    cout << "The linked list is: ";
    printList(head);
    int total = countNodes(head);
    cout << "Total number of nodes: " << total << endl;
    return 0;
}
