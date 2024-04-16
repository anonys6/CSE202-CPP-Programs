// #include <iostream>

// using namespace std;

// int toh(int n, char rod_A, char rod_C, char rod_B) {
//     if (n == 1) {
//         cout << "Move disk " << n << " from " << rod_A << " to " << rod_C << endl;
//         return 1;
//     }

//     int moves = 0;

//     moves = moves + toh(n - 1, rod_A, rod_B, rod_C);

//     cout << "Move disk " << n << " from " << rod_A << " to " << rod_C << endl;
//     moves++;

//     moves = moves + toh(n-1, rod_B, rod_C, rod_A);

//     return moves;
// }

// int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int n;

//     cin >> n;

//     int moves = toh(n, 'A', 'C', 'B');

//     cout << "Total number of moves: " << moves << endl;

//     return 0;
// }


#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int toh(int n, char rodA, char rodC, char rodB) {
    if (n == 1) {
        cout << "Move disk " << n << " from " << rodA << " to " << rodC << endl;
        return 1;
    }

    int moves = 0;
    moves = moves + toh(n - 1, rodA, rodB, rodC);

    cout << "Move disk " << n << " from " << rodA << " to " << rodC << endl;
    moves++;
    
    moves = moves + toh(n - 1, rodB, rodC, rodA);
    return moves;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int moves = toh(n, 'A', 'C', 'B');

    cout << "Total number of moves: " << moves << endl;

    return 0;
}

int tower_of_hanoi(int n, char a, char c, char b) {
    if (n == 1) {
        cout << "Move disk " << n <<" from " << a << " to " << c << endl;
    }

    int moves = 0;
    moves = moves + tower_of_hanoi(n - 1, a, c, b);

    cout << "Move disk " << n << " from disk " << a << " to " << c << endl;
    moves++;

    moves = moves + tower_of_hanoi(n - 1, b, c, a);
    return moves;
}