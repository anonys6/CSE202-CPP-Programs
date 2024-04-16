#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream fout;

    string line;

    fout.open("40_files_of.txt");

    while (fout) {
        getline(cin, line);

        if (line == "-1") {
            break;
        }

        fout << line << endl;
    }

    fout.close();

    ifstream fin;

    fin.open("40_files_of.txt");

    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();

    return 0;
}