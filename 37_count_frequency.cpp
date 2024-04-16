#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int arr[] = {1, 3, 4, 2, 2, 5, 4, 1, 1, 1};

    unordered_map<int, int> m;

    for (int i = 0; i < 10; i++) {
        m[arr[i]]++;
    }

    for (auto curr : m) {
        cout << curr.first << " " << curr.second << endl;
    }

    return 0;
}