#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> m;

    // m["hi"] = "one";
    m[1] = "one";
    m[2] = "two";

    m.insert(make_pair(3, "three"));

    // cout << m["hi"];
    cout << m[3];

    cout << endl;

    if (m.find(1) != m.end()) {
        cout << "Key is present" << endl;
    } else {
        cout << "Key is not present" << endl;
    }

    for (auto curr : m) {
        cout << curr.first << " " << curr.second << endl;
    }

    m.erase(3);

    cout << "**************************" << endl << endl;

    for (auto curr : m) {
        cout << curr.first << " " << curr.second << endl;
    }

    return 0;
}