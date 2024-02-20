#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 4, 3, 3, 3, 2, 4};

    cout << "Vector: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    // sort( vec.begin(), vec.end() );
    // vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

    set<int> s(vec.begin(), vec.end());
    vec.assign(s.begin(), s.end());

    cout << "\nVector after removing duplicates: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    return 0;
}

// 2954
// 26612