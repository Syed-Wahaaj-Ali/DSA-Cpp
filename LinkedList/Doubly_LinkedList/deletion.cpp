#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void printListForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printListBackward(Node* tail) {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Delete node at beginning
void deleteAtBeginning(Node*& head, Node*& tail) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        // list became empty
        tail = nullptr;
    }

    delete temp;
}

// Delete node at end
void deleteAtEnd(Node*& head, Node*& tail) {
    if (tail == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        // list became empty
        head = nullptr;
    }

    delete temp;
}

// Delete node by value
void deleteByValue(Node*& head, Node*& tail, int value) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;

    // search for the node
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value not found in the list." << endl;
        return;
    }

    // unlink the node
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // node was head
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // node was tail
    }

    delete temp;
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

        // insert at end for simplicity
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

    cout << "Initial list forward: ";
    printListForward(head);

    cout << "Enter value to delete at beginning: ";
    deleteAtBeginning(head, tail);
    printListForward(head);

    cout << "Enter value to delete at end: ";
    deleteAtEnd(head, tail);
    printListForward(head);

    cout << "Enter value to delete by value: ";
    cin >> value;
    deleteByValue(head, tail, value);
    printListForward(head);

    return 0;
}
