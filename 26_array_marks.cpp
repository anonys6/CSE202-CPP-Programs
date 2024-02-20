#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum = sum + arr[i][j];
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
        cout << "Average Student " << i << ": " << sum / m << endl;
    }

    return 0;
}

/*
INPUT
3
4
80 90 75 85
90 85 95 92
45 43 22 44
*/