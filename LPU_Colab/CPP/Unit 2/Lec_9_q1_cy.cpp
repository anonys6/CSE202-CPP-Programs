#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> vec = {1, 2, 3, 4, 5};
    
    vector <int> odd;

    int flag = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 != 0) {
            odd.push_back(vec[i]);
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "Invalid Input" << endl;
    } else {
        for (auto i : odd) {
            cout << i << " ";
        }
    }

    return 0;
}