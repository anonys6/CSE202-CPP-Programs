#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int sum = 0;

    while (num > 0) {
        int rem = num % 10;
        sum = sum = rem;
        num = num / 10;
    }

    int temp = sum;
    int reverse = 0;

    while (sum > 0) {
        int rem = sum % 10;
        reverse = reverse * 10 + rem;
        sum = sum / 10;
    }

    if (reverse == temp) {
        cout << "Number sum is palindrome";
    } else {
        cout << "Number sum is not palindrome";
    }

    return 0;
}