#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream myFile;

    string str;
    getline(cin, str);
    
    myFile.open("string.txt", ios::app);

    if(!myFile.is_open()) {
        cout << "Cannot open file" << endl;
        return 1;
    } else {
        myFile << str << endl;
    }

    myFile.close();

    cout << "Data appended successfully" << endl;

    return 0;
}