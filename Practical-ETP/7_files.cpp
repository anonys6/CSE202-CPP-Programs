#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fstream myFile;

    // write in file
    myFile.open("7_files.txt", ios::out); // to write in file
    if (myFile.is_open()) {
        myFile << "Hello" << endl;
        myFile << "This is second line" << endl;
        myFile.close();
    }

    // append a file
    myFile.open ("7_files.txt", ios::app);
    if (myFile.is_open()) {
        myFile << "Hello2" << endl;
        myFile.close();
    }

    // read my file
    myFile.open("7_files.txt", ios::in);
    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    }


    // read a file
    myFile.open("7_files.txt", ios::in);
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

void file() {
    fstream myFile;

    myFile.open("file.txt", ios::in);
    if (myFile.is_open()) {
        string line;
        while(getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    }

    myFile.open("file.txt", ios::out);
    if (myFile.is_open()) {
        cout << "in my file" << endl;

        myFile.close();
    }
}