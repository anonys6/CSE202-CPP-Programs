#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int inum;
    float dnum;
    string str;
    int inum_read;
    float dnum_read;
    string str_read;

    cin >> inum >> dnum >> str;

    ofstream outfile("test.txt");

    if (!outfile.is_open())
    {
        cout << "Cannot open file." << endl;
        return 1;
    }
    else
    {
        outfile << inum << endl;
        outfile << dnum << endl;
        outfile << str << endl;
    }

    outfile.close();

    ifstream infile;
    infile.open("test.txt");

    if (!infile.is_open())
    {
        cout << "Cannot open file." << endl;
        return 1;
    }
    else
    {
        infile >> inum_read;
        infile >> dnum_read;
        infile >> str_read;
    }

    infile.close();

    float sum = inum_read + dnum_read;

    cout << inum_read << endl;
    cout << dnum_read << endl;
    cout << str_read << endl;
    cout << "Sum of integer and float: " << sum << endl;

    return 0;
}