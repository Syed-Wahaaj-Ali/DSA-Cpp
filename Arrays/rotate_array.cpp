#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of positions to rotate (k): ";
    cin >> k;

    k = k % n; // handle if k > n

    cout << "Array after rotation: ";
    for (int i = k; i < n; i++) {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
