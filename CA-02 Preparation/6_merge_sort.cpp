#include <iostream>

using namespace std;

void mergeSort(int * arr, int low, int high) {
    int mid;
    if (low < high) {
        // Calculating the mid.
        mid = (low + high) / 2;

        // Calling the function mergeSort() recursively and breaking down the given array into smaller sub arrays.
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Calling the merge() function to merge the sorted subarrays into the main array.
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[4] = {3, 2, 5, 6};

    mergeSort(arr, 2, 6);

    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }


    
    return 0;
}