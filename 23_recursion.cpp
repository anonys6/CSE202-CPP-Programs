#include <iostream>

using namespace std;

// int sum(int num) {
//     if (num == 0) {
//         return num;
//     } else {
//         return num + sum(num-1);
//     }
// }

int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int fibo(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int raisePower(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return x * raisePower(x, y - 1);
    }
}

// string xPower (int n) {
//     if (n == 1) {
//         return "1";
//     }

//     string recAns = xPower(n - 1);

//     return myAns;
// }

string xPower(int n) {
    if (n == 1) {
        return "1";
    }

    string recAns = xPower(n - 1);

    // string myAns = to_string(n) + recAns + "x^" << to_string(n - 1);
    string myAns = recAns + " + " + to_string(n) + "x^" + to_string(n - 1);

    return myAns;
}

// int raisePower(int x, int y) {
//     if (y == 1) {
//         return 1;
//     }
//     int recAns = raisePower(x, y - 1);
//     int myAns = x * myAns;
//     return myAns;
// }

int main() {
    // int num;
    // cout << "Enter a number: ";
    // cin >> num;

    // cout << sum(num);
    cout << xPower(4);

    return 0;
}