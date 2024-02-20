#include <iostream>
#include <string>

using namespace std;

class Test {
    string name;

  public:
    Test(string name) { this->name = name; }

    ~Test() { cout << this->name << endl; }
};

int main() {
    Test t1("A");
    Test t2("C");
    Test t3("B");
    return 0;
}