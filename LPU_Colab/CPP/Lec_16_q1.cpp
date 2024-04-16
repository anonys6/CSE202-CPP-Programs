#include <iostream>

using namespace std;

class Employee {
    public:
        static int count;
        Employee() {
            cout << "Created " << count << endl;
            count++;
        }

        ~Employee() {
            count--;
            cout << "Destroyed " << count << endl;
        }


};

int Employee::count = 1;

int main() {
    Employee emp[3];
}