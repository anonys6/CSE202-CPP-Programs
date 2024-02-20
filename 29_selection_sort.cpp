#include <iostream>

using namespace std;

void selection_sort(int arr[], int n) {
    int min;

    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(arr[min], arr[i]);
        }

        for (int k = 0; k < 5; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[5] = {64, 25, 12, 22, 11};

    selection_sort(arr, 5);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}