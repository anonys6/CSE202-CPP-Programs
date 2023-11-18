#include <iostream>
#include <string>
#include <cstring>



using namespace std;

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1 = "Hello";
    string s2 = "World";

    cout << s1 + " " + s2 << endl;

    // String methods
    cout << s1.length() << endl;
    cout << s1.substr(1, 3) << endl;
    cout << s1.find("ll") << endl;
    cout << s1.compare(s2) << endl;

    // String to char array
    char str[10];
    strcpy(str, s1.c_str());
    cout << str << endl;

    // Char array to string
    char str2[10] = "Hello";
    string s3(str2);
    cout << s3 << endl;
    
    return 0;
}