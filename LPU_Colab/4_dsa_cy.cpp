#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findSmallestMissingPositive(const vector<int> &arr, int x)
{
    int n = arr.size();
    int missing = x + 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= x)
        {
            continue;
        }
        else if (arr[i] == missing)
        {
            missing++;
        }
        else
        {
            break;
        }
    }

    return missing;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    sort(arr.begin(), arr.end());

    int result = findSmallestMissingPositive(arr, x);
    cout << "The smallest missing positive integer greater than " << x << " is " << result << "." << endl;

    return 0;
}
