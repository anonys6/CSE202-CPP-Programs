#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    string l = "";

    for (int i = 0; i < s.length(); i++) {
        int flag = 0;
        for (int j = 0; j < s.length(); j++) {
            if (i == j) {
                continue;
            }
            if (s[i] == s[j]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            l = l + s[i];
        }
    }

    cout << "String: " << l;
}