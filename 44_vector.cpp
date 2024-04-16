#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, val;

    vector<int> vec;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    print(vec);

    int pos;
    cin >> pos >> val;

    vec.insert(vec.begin() + pos, val);

    print(vec);

    return 0;
}