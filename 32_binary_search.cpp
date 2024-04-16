#include <bits/stdc++.h>

using namespace std;

int rBinarySearch(int arr[], int lo, int hi, int x) {
    if (lo <= hi) // Check if their is still elements left to check.
    {
        int mid = lo + (hi - lo) / 2; // Calculate index of middle element.
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x) // Recursive call for left sub-array.
            return rBinarySearch(arr, lo, mid - 1, x);

        else // Recursive call for right sub-array.
            return rBinarySearch(arr, mid + 1, hi, x);
    }

    return -1; // If key not present in array.
}

// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 6, 8, 10};
    int x = 8;                             // Key to be searched.
    int pos = rBinarySearch(arr, 0, 6, x); // Call binary search function.
    if (pos != -1)
        cout << "Element is present at position " << pos << "\n";
    else
        cout << "Element not found\n";

    x = 5;                             // Key to be searched.
    pos = rBinarySearch(arr, 0, 6, x); // Call binary search function
    if (pos != -1)
        cout << "Element is present at position " << pos << "\n";
    else
        cout << "Element not found\n";

    return 0;
}
