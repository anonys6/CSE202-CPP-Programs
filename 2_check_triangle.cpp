#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Enter angles of triangle: ";
    cin >> a >> b >> c;
    if (a * a + b * b == c * c || a * a + c * c == b * b ||
        b * b + c * c == a * a)
        cout << "Right Angle";
    else
        cout << "Not Right Angle";
    return 0;
}