#include <iostream>
#include <vector>

using namespace std;

// Bubble sort
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no swapping happened, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}


// Selection sort
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}


// Insertion sort
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert the key at its correct position in the sorted array
        arr[j + 1] = key;
    }
}


// Merge sort
void merge(vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m; // Size of right subarray
    // Create temporary arrays
    vector<int> L(n1), R(n2);
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }
    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        // Copy the smaller element from the two subarrays into arr
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k++] = L[i++];
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        // Same as (l + r) / 2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}


// Quick sort
int partition(vector<int> &arr, int l, int r) {
    int pivot = arr[r]; // Pivot element
    int i = l - 1; // Index of smaller element
    for (int j = l; j < r; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r); // Partitioning index
        // Sort elements before and after partition
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}


void print(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr = {5, 2, 4, 6, 1, 3};

    bubbleSort(arr);
    print(arr);
    
    arr = {5, 2, 4, 6, 1, 3};
    selectionSort(arr);
    print(arr);

    arr = {5, 2, 4, 6, 1, 3};
    insertionSort(arr);
    print(arr);

    arr = {5, 2, 4, 6, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);
    print(arr);

    arr = {5, 2, 4, 6, 1, 3};
    quickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}