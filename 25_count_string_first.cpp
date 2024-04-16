#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> v1 = {1, 2, 3, 4, 5};

    vector<int> v;

    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(1);

    // cout << v.front();

    v.insert(v.begin() + 1, 6);

    // v.pop_back();

    // sort(v.begin(), v.end(), greater<int>());

    // reverse(v.begin(), v.end());

    // v1.insert(v1.end(), v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
}