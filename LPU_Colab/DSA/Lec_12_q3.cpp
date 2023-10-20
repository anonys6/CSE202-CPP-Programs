#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    string val;
    cin >> n;
    
    cin.ignore();
    
    queue<string> q;
    
    for (int i = 0; i <= n; i++) {
        getline(cin, val);
        q.push(val);
    }
    // q.pop();
    
    cout << "Message Queue:" << endl;
    
    while(!q.empty()) {
        cout << "- " << q.front() << endl;
        q.pop();
    }
    
    return 0;
}