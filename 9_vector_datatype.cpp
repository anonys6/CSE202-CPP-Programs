#include <iostream>
#include <vector>
using namespace std;

int main()

{
    vector<int> num;

    vector<int> num1 = {1, 2, 3, 4, 5};
    vector<int> num2{1, 2, 3};
    vector<int> num3(5, 12);

    // for (const int &i : num1)
    // {
    //     cout << i << "  ";
    // }

    for (int i = 0; i < num1.size(); i++)
    {
        cout << num1[i] << " ";
        cout << num1.at(i) << " ";
    }

    num1.push_back(6);

    for (const int &i : num1)
    {
        cout << i << " ";
    }

    cout << endl
         << "Print: " << num1[9] << num1.at(9);

    return 0;
}