#include <iostream>
using namespace std;

// Node structure for stack (linked list)
struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;  // pointer to top of stack (just like a head of a Linkedlist)

public:
    Stack() {
        top = nullptr; // stack empty at start
    }

    // push element onto stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;  // new node points to old top just like we do in normal linkedlist 
        top = newNode;        // update top like we do in head of linkedlist
        cout << value << " pushed into stack" << endl;
    }

    // pop element from stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow (stack is empty)" << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack" << endl;
        top = top->next;
        delete temp;
    }

    // view top element
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }

    // display all elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    st.peek();

    st.pop();
    st.display();
    return 0;
}
