#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a[5] = {14, 4, 5, 2, 13};
    vector<int> vec(a, a + 5); // Convert array to vector

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 5 - k; i++) {
            if (vec[i] > vec[i + 1]) {
                int temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << vec[i] << " ";
    }
}