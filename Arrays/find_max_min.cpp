#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 25, 3, 56, 7, 99, 18};
    int n = 7;

    int maxNum = arr[0];
    int minNum = arr[0];

    // check each element
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
        if (arr[i] < minNum) {
            minNum = arr[i];
        }
    }

    cout << "Maximum value: " << maxNum << endl;
    cout << "Minimum value: " << minNum << endl;

    return 0;
}
