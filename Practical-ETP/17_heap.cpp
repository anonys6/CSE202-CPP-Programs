#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v) {
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

    cout << "Normal vector: ";
    print_vector(vec);

    make_heap(vec.begin(), vec.end());
    cout << "After make_heap(): ";
    print_vector(vec);

    pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    cout << "After popping heap using pop_heap(): ";
    print_vector(vec);

    vec.push_back(8);
    push_heap(vec.begin(), vec.end());
    cout << "push_heap 4: ";
    print_vector(vec);
    cout << "is_heap: " << is_heap(vec.begin(), vec.end()) << endl;

    sort_heap(vec.begin(), vec.end());
    cout << "After sorting the heap" << endl;
    print_vector(vec);

    cout << "is_heap: " << is_heap(vec.begin(), vec.end()) << endl;


    return 0;
}