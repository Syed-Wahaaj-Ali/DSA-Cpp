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

// Delete node from the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* temp = head;   // store current head
    head = head->next;   // move head to next
    delete temp;         // free memory
}

// Delete node from the end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->next == nullptr) {
        // only one node in list
        delete head;
        head = nullptr;
        return;
    }

    // move to second last node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;   // delete last node
    temp->next = nullptr; // mark end
}

// Delete node by value (returns true if deleted, false if not found)
bool deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return false;
    }

    // if head itself has the value
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // search for node with the value
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        // value not found
        return false;
    }

    // unlink the node
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return true;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter number of initial nodes: ";
    cin >> n;

    // create list
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        // insert at end for simplicity
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

    cout << "Initial List: ";
    printList(head);

    // delete at beginning
    deleteAtBeginning(head);
    cout << "List after deleting at beginning: ";
    printList(head);

    // delete at end
    deleteAtEnd(head);
    cout << "List after deleting at end: ";
    printList(head);

    // delete by value
    int val;
    cout << "Enter value to delete: ";
    cin >> val;
    if (deleteByValue(head, val)) {
        cout << "List after deleting value " << val << ": ";
        printList(head);
    } else {
        cout << "Value " << val << " not found in list. List remains the same: ";
        printList(head);
    }
    return 0;
}
