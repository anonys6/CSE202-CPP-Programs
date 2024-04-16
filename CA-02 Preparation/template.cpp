#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int x, y;
    cin >> x >> y;

    cout << x * y;

    return 0;
}