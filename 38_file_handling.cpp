#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    fstream myFile;

    // // write in file
    // myFile.open("38_file.txt", ios::out);
    // if (myFile.is_open()) {
    //     myFile << "Hello" << endl;
    //     myFile << "This is second line" << endl;
    //     myFile.close();
    // }

    // // append a file
    // myFile.open ("38_file.txt", ios::app);
    // if (myFile.is_open()) {
    //     myFile << "Hello2" << endl;
    //     myFile.close();
    // }

    // read a file
    myFile.open("38_file.txt", ios::in);
    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            fstream myFile2;
            myFile2.open("38_file2.txt", ios::app);
            if (myFile2.is_open()) {
                myFile2 << line << endl;
                myFile2.close();
            }
            cout << line << endl;
        }
    }

    return 0;
}