// /*
// queue::empty()	O(1)
// queue::size()	O(1)
// queue::emplace()	O(1)
// queue::front()	O(1)
// queue::back()	O(1)
// queue::push(g) 	O(1)
// queue::pop() 	O(1)
// */

#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> q) {
    queue<int> temp = q;

    while(!temp.empty()) {
        cout << temp.front() << " ";
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

    queue<int> q;

    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    cout << "Print queue: ";
    print(q);

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Size of the queue: " << q.size() << endl;

    q.pop();
    q.pop();
    cout << "After popping two element: ";
    print(q);

    return 0;    
}