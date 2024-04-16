#include <iostream>
#include <algorithm>

using namespace std;

int findTriplet(int arr[], int n)
{
    sort(arr, arr + n);

    int i = 0, j = n - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == 0)
        {
            return 1;
        }

        else if (arr[i] + arr[j] < 0)
        {
            i++;
        }

        else
        {
            j--;
        }
    }

    return 0;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    int arr[n];
    cout << "arr{} = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = findTriplet(arr, n);

    if (result == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}
