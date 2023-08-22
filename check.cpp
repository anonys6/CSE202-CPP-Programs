#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxWater = 0;

    while (left < right)
    {
        int h = min(height[left], height[right]);
        int w = right - left;
        maxWater = max(maxWater, h * w);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxWater;
}

int main()
{
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the lines:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> height[i];
    }

    int result = maxArea(height);
    cout << "Maximum amount of water that can be stored: " << result << endl;

    return 0;
}
