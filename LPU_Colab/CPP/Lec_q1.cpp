// #include <iostream>
// #include <fstream>

// using namespace std;

// int main() {
//     int a, b;
//     cin >> a >> b;

//     fstream myFile;

//     myFile.open("sum.txt", ios::out);

//     if (!myFile.is_open()) {
//         cout << "Error opening the file 'sum.txt'" << endl;
//         return 1;
//     } else {
//         myFile << a + b;
//     }

//     myFile.close();

//     return 0;
// }
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n1, n2;

    cin >> n1 >> n2;

    int sum = n1 + n2;

    ofstream outFile("sum.txt");

    if (!outFile.is_open()) {
        cerr << "Error opening the file 'sum.txt'" << endl;
        return 1; 
    }

    outFile << "Sum successfully written to the file 'sum.txt'." << endl;
    outFile << "Sum: " << sum << endl;

    outFile.close();

    cout << "Sum successfully written to the file 'sum.txt'." << endl;
    cout << "Sum: " << sum << endl;

    return 0; 
}
