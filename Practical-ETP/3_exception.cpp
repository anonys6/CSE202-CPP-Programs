#include <iostream>
#include <exception>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int age;
    cin >> age;

    try {
        if (age >= 18) {
            cout << "Access given" << endl;
        } else {
            throw age;
        }
    }
    catch (int age) {
        cout << "Age : " << age <<", Access denied" << endl;
    }

    return 0;
}