#include <iostream>
using namespace std;

void foo() {
    try {
        throw runtime_error("Exception!");
    }
    catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
        throw;
    }
}

int main() {
    try {
        foo();
    }
    catch (const exception& e) {
        cout << "Caught rethrown exception: " << e.what() << endl;
    }
    return 0;
}