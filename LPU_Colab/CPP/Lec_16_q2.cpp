#include <iostream>

using namespace std;

int main() {
    int r1 = 50, r2 = 42, p1 = 85, p2 = 65;

    int flag = 0;

    float sum = 0;

    p1 = p1 + p2;
    r1 = r1 + r2;

    if (p1 > 99) {
        sum = r1 + 1 + (p1 % 10);
    } else {
        sum = r1 + (p1 % 10);
    }

    cout << sum;
}