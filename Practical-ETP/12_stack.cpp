#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> s) {
    stack<int> temp = s;
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

    stack<int> s;

    for (int i = 0; i < n; i++) {
        cin >> val;
        s.push(val);
    }

    cout << "Print stack" << endl;
    print(s);

    cout << "Top element: " << s.top() << endl;
    cout << "Size of the stack: " << s.size() << endl;

    return 0;
}