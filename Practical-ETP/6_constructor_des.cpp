/*

Constructor types in c++
1. Default constructor : Implicitly called when object is created, no arguments
2. Parameterized constructor : Explicitly called when object is created, arguments
3. Copy constructor : Implicitly called when object is created from another object of same class
4. Destructor : Implicitly called when object is destroyed

*/

#include <iostream>

using namespace std;

class A {
    public:

        A() {
            cout << "Default constructor" << endl;
        }

        A(int a) {
            cout << "Parameterized constructor" << endl;
        }

        A(A &a) {
            cout << "Copy constructor" << endl;
        }

        ~A() {
            cout << "Destructor" << endl;
        }
};


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    A b;
    A c(10); // Parameterized constructor
    A d(b); // Copy constructor

    return 0;
}