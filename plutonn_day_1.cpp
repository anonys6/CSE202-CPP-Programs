#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int maximumArea(vector<int> &height)
{
    int max_area = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            max_area = max(max_area, min(height[i], height[j]) * (j - i));
        }
    }
    return max_area;
}

int main()
{
    string input;
    cout << "height = ";
    getline(cin, input);

    input = input.substr(1, input.size() - 2);

    vector<int> height;
    stringstream ss(input);
    string item;
    while (getline(ss, item, ','))
    {
        height.push_back(stoi(item));
    }

    int max_area = maximumArea(height);
    cout << max_area << endl;

    return 0;
}
