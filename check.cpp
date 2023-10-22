#include <iostream>
using namespace std;

class A {
public:
    string x;
    A() { x = "Hello"; cout << x << " "; }
    ~A() { x += " World"; cout << x << " "; }
};

class B : public A {
public:
    string y;
    B() { y = "C++"; cout << y << " "; }
    ~B() { y = "Welcome"; cout << y << " "; }
};

int main() {
    B obj;
    cout << obj.x << " " << obj.y << endl;
    return 0;
}