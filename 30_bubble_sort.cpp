#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }

        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[5] = {54, 12, 64, 42, 15};

    bubble_sort(arr, 5);

    cout << endl << "Bubble Sort" << endl;
    for (int j = 0; j < 5; j++) {
        cout << arr[j] << " ";
    }

    return 0;
}