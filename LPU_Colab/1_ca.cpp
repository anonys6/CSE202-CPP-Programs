#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i =1; i <= n; i++) {
        cout << i << setw(7) << pow(i, 2) << endl;
    }
    
    return 0;
}