#include <iostream>
// #include <cmath>
// #include <vector>
// #include <cstring>
#include <algorithm>
// #include <string>
// #include <stack>
#include <string.h>

using namespace std;

// void modify(int *arr)
// {
//     rotate(arr, arr + 3, arr + 5);
//     rotate(arr, arr + 2; arr + 4);
// }

bool compare(char c1, char c2)
{
    return tolower(c1) > tolower(c2);
}

int main()
{
    // int n = 4;
    // std ::cout << std::pow(n, 2) << " " << std::sqrt(n);
    // cout << pow(n, 2) << " " << sqrt(n);

    // vector<int> arr;
    // vector<int> arr(3);
    // vector<int> arr[3];
    // int arr[3];

    // arr.resize(10);
    // for (int i = 0; i < 10; i++)
    //     arr[i] = i + 1;

    // string s = "programming in modern C++";
    // cout << s.size();
    // cout << strlen(s);
    // cout << s.length();
    // cout << strlen(s.c_str());

    // int data[] = {50, 30, 40, 10, 20};
    // sort(&data[2], &data[5]);
    // for (int i = 0; i < 5; i++)
    //     cout << data[i] << " ";

    // string str1 = "Welcome ";
    // string str2 = "students";
    // // str1 += str2;
    // // strcat(str1, str2);
    // // str1.append(str2);
    // // str1.insert(str2);
    // cout << str1;

    // char str[10] = "COMPUTER";
    // stack<char> s1, s2;
    // int i;
    // for (i = 0; i < strlen(str) / 3; i++)
    //     s1.push(str[i]);
    // for (; i < strlen(str); i++)
    //     s2.push(str[i]);
    // while (!s1.empty())
    // {
    //     s2.push(s1.top());
    //     s1.pop();
    // }
    // while (!s2.empty())
    // {
    //     cout << s2.top();
    //     s2.pop();
    // }

    // int iarr[5];
    // for (int i = 0; i < 5; i++)
    //     *(iarr + i) = i * 2;
    // modify(iarr);
    // for (int i = 0; i < 5; ++i)
    //     cout << *(iarr + i) << " ";

    // int iarr[] = {10, 20, 50, 40, 10, 50};
    // rotate(&iarr[0], &iarr[2], &iarr[6]);
    // remove(&iarr[0], &iarr[6], 10);
    // for (int i = 0; i < 4; ++i)
    //     cout << iarr[i] << " ";

    char arr1[20] = "C++ Program", arr2[20] = "C Program";
    cout << lexicographical_compare(arr1, arr1 + strlen(arr1), arr2, arr2 + 5, compare);

    return 0;
}