#include <boost/variant.hpp> // Add missing import
#include <iostream>

using namespace std; // Add missing import

class Parent {
  public:
    virtual void display() { cout << "VDParent"; }
    void fun() { cout << "Parent"; }
};

class Child : public Parent {
  public:
    void display() { cout << "DParent"; }
    void fun() { cout << "Child"; }
};

int main() {
    union A {
        boost::variant<int, float, string>
            name; // Fix incomplete union declaration
    };

    A a;
    a.name = 10;

    Parent *p;
    Child c;

    p = &c;

    p->display();

    // Parent p = Child();
    // p.fun();

    return 0;
}