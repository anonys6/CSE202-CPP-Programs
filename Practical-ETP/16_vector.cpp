#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, val;
    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "Print vector: ";
    print(vec);

    vector<int> temp = vec;
    sort(temp.begin(), temp.end());
    cout << "Sorted vector: ";
    print(temp);

    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    cout << "Unique element (sorted vector): ";
    print(temp);

    temp = vec;
    set<int> s(temp.begin(), temp.end());
    temp.assign(s.begin(), s.end());
    cout << "Unique element (unsorted): ";
    print(temp);

    return 0;
}