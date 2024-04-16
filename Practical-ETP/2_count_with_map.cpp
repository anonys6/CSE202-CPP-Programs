// You are using GCC
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int num;
    cin >> num;
    
    map <int, int> countDigit;
    
    while (num > 0) {
        int rem = num % 10;
        countDigit[rem]++;
        num /= 10;
    }
    
    for (int i = 0; i < 10; i++) {
        if (countDigit[i] > 0)
            cout << "Digit " << i << ": " << setw(2) << countDigit[i] << " times" <<endl;
    }
    
    return 0;
}