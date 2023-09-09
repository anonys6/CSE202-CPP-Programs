#include <iostream>

using namespace std;

void insertion_sort(int arr[], int n) {
    int key;

    cout << "Iterstions:" << endl;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;

        for (int k = 0; k < 5; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[5] = {54, 12, 64, 42, 15};

    insertion_sort(arr, 5);

    cout << "Insertion Sort" << endl;
    for (int j = 0; j < 5; j++) {
        cout << arr[j] << " ";
    }
    
    return 0;
}