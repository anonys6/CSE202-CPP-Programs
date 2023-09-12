#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    int N;
    cin >> N;

    int sum = 0;
    while (N > 0)
    {
        int rem = N % 10;
        sum = sum + rem;
        N = N / 10;
    }

    int temp = sum;

    int reversed = 0;

    while (sum > 0)
    {
        int digit = sum % 10;
        reversed = reversed * 10 + digit;
        sum = sum / 10;
    }

    // if (temp == reversed)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }

    if (temp == reversed)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}