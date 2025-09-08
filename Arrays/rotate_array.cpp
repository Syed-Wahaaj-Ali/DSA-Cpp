#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original array: ";
    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // store last element
    int last = arr[n-1];

    // shift elements to the right
    for (int i = n-1; i>0; i--) {
        arr[i] = arr[i-1];
    }

    // put last element at first position
    arr[0] = last;

    cout << "Array after rotation: ";
    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
