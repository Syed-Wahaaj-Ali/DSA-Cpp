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

// Function to merge two sorted lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    Node* mergedHead = nullptr;
    Node* mergedTail = nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 != nullptr && temp2 != nullptr) {
        int value;
        if (temp1->data < temp2->data) {
            value = temp1->data;
            temp1 = temp1->next;
        } else {
            value = temp2->data;
            temp2 = temp2->next;
        }
        insertAtEnd(mergedHead, mergedTail, value);
    }

    // Add remaining nodes
    while (temp1 != nullptr) {
        insertAtEnd(mergedHead, mergedTail, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        insertAtEnd(mergedHead, mergedTail, temp2->data);
        temp2 = temp2->next;
    }
    return mergedHead;
}

int main() {
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    int n1, n2, value;

    // First list
    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head1, tail1, value);
    }

    // Second list
    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head2, tail2, value);
    }

    cout << "First list: ";
    printList(head1);
    cout << "Second list: ";
    printList(head2);

    Node* mergedHead = mergeSortedLists(head1, head2);
    cout << "Merged sorted list: ";

    printList(mergedHead);
    return 0;
}
