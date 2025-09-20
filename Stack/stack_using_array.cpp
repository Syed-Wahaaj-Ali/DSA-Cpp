#include <iostream>
using namespace std;

#define MAX 100   // max size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1; // stack is empty at start
    }

    // push element onto stack
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow (stack is full)" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    // pop element from stack
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow (stack is empty)" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack" << endl;
    }

    // view top element
    void peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    // display all elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
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
