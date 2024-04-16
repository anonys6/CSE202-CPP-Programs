#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    // Min PQ

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(6);
    pq.push(2);
    pq.push(8);
    pq.push(1);

    cout << pq.top() << endl;

    // pq.pop();

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Max PQ

    // priority_queue<int> pq;
    // pq.push(5);
    // pq.push(6);
    // pq.push(2);
    // pq.push(8);
    // pq.push(1);

    // cout << pq.top() << endl;

    // // pq.pop();

    // while(!pq.empty()) {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    // cout << pq.top() << endl;

    return 0;
}