t(int arr[], int n) {
    int min;

    for (int i = 0; i < n - 1; i++) {
        min = i;

        for(int j = i + 1; j < n; j++) {
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