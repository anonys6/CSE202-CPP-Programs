#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n) {
    bool swapped;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        for (int k = 0; k < 5; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[5] = {54, 12, 64, 42, 15};

    bubble_sort(arr, 5);

    for (int j = 0; j < 5; j++) {
        cout << arr[j] << " ";
    }
    
    return 0;
}