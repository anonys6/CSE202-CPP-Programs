#include <iostream>
#include <deque>

using namespace std;

void print (deque<int> d) {
    deque<int> temp = d;

    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop_front();
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

    deque<int> myDeque;

    for (int i = 0; i < n; i++) {
        cin >> val;
        myDeque.push_back(val);
    }

    cout << "Deque: ";
    print(myDeque);

    cout << "Front element: " << myDeque.front() << endl;
    cout << "Back element: " << myDeque.back() << endl;
    cout << "Size of the deque: " << myDeque.size() << endl;

    myDeque.pop_front();
    myDeque.pop_back();
    cout << "After popping two elements: ";
    print(myDeque);

    return 0;
}