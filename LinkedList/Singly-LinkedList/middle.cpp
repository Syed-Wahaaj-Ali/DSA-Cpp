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

// Function to find the middle node(s)
void findMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // first count total nodes
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    temp = head;
    int mid = count / 2;

    // if odd - single middle
    if (count % 2 != 0) {
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        cout << "Middle element is: " << temp->data << endl;
    } 
    // if even - two middles
    else {
        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }
        cout << "Middle elements are: " << temp->data << " and " << temp->next->data << endl;
    }
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

    // find and print middle
    findMiddle(head);
    return 0;
}
