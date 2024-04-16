#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str = "Hi, how are you? Hope this code helps you to learn. Happy Learning!! - 01245";

    int count = 0;

    istringstream iss (str);
    string word;

    while (iss >> word) {
        count++;
    }

    cout << count;

    return 0;
}