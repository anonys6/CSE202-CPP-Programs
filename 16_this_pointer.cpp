#include <iostream>
using namespace std;

class A {
  public:
    static void fun() { cout << "Fun"; }
};

int main() { A::fun(); }