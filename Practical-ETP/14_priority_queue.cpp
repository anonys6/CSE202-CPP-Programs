#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print(priority_queue<int> p) {
    priority_queue<int> temp = p;

    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
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

    priority_queue<int> pq;
    // priority_queue<int, vector<int>, greater<int>()> pq;

    for (int i = 0; i < n; i++) {
        cin >> val;
        pq.push(val);
    }

    cout << "Priority queue: ";
    print(pq);

    cout << "Top element: " << pq.top() << endl;
    cout << "Size of the queue: " << pq.size() << endl;

    pq.pop();
    pq.pop();
    cout << "After popping two elements: ";
    print(pq);

    return 0;
}