#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert node at end of the list
void insertAtEnd(Node*& head, int value) {
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

// Function to print the list
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

    while (head1 != nullptr && head2 != nullptr) {
        Node* temp;
        if (head1->data < head2->data) {
            temp = head1;
            head1 = head1->next;
        } else {
            temp = head2;
            head2 = head2->next;
        }

        if (mergedHead == nullptr) {
            mergedHead = temp;
            mergedTail = temp;
        } else {
            mergedTail->next = temp;
            mergedTail = temp;
        }
    }

    // Attach the remaining part
    if (head1 != nullptr) mergedTail->next = head1;
    if (head2 != nullptr) mergedTail->next = head2;
    return mergedHead;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int n1, n2, value;
    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head1, value);
    }

    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head2, value);
    }

    cout << "First List: ";
    printList(head1);
    cout << "Second List: ";
    printList(head2);

    Node* merged = mergeSortedLists(head1, head2);
    cout << "Merged Sorted List: ";
    printList(merged);
    return 0;
}
