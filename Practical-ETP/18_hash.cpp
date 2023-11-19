#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    char ch = 'c';

    hash<char> hash_char;

    cout << hash_char(ch) << endl;

}