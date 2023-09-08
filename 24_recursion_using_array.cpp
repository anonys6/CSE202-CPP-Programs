#include <iostream>
#include <vector>

using namespace std;

// void printUsingRec(int arr[], int n, int si) {
//     if(si == n) {
//         return ;
//     }

//     cout << arr[si] << " ";

//     printUsingRec(arr, n, si + 1);
// }

// void printUsingRec(int arr[], int n, int si)
// {
//     if (si == n)
//     {
//         return;
//     }

//     printUsingRec(arr, n, si + 1);

//     cout << arr[si] << " ";
// }

// int linearSearchRecursive(int arr[], int n, int si, int x) {
//     if (si == n) {
//         return false;
//     }

//     int recAns = linearSearchRecursive(arr, n, si + 1, x);

//     if(recAns) {
//         return si;
//     }

//     if(arr[si] == x) {
//         return si;
//     }

//     return false;
// }

// int lastIndex(int arr[], int n, int si, int x) {
//     if (si == n) {
//         return -1;
//     }

//     int recAns = lastIndex(arr, n, si + 1, x);

//     if (recAns != -1) {
//         return recAns;
//     }

//     if (arr[si] == x) {
//         return si;
//     }

//     return -1;
// }

vector<int> allIndices (int arr[], int n, int si, int x) {

    if (n == si) {
        vector <int> v;
        return v;
    }

    vector <int> smallAns = allIndices(arr, n, si + 1, x);

    if (arr[si] == x) {
        smallAns.insert(smallAns.begin(), si);
    }

    return smallAns;
}
// return all the indices combination whose sum is equal to x
// vector<vector<int>> arraySumX(int arr[], int n, int si, int x) {
//     if (si == n) {
//         vector<vector<int>> v;
//         return v;
//     }

//     vector<vector<int>> smallAns = arraySumX(arr, n, si + 1, x);

//     if (arr[si] == x) {
//         vector<int> v;
//         v.push_back(arr[si]);
//         smallAns.push_back(v);
//     }

//     for (int i = 0; i < smallAns.size(); i++) {
//         smallAns[i].push_back(arr[si]);
//     }

//     return smallAns;
// }

// Return all the indices combination whose sum is equal to x
vector<vector<int>> arraySumX(int arr[], int n, int si, int x) {
  if (si == n) {
    vector<vector<int>> ans;
    return ans;
  }

  vector<vector<int>> smallAns = arraySumX(arr, n, si + 1, x);

  if (arr[si] == x) {
    vector<int> v = {arr[si]};
    smallAns.push_back(v);
  }

  for (vector<int>& v : smallAns) {
    v.push_back(arr[si]);
  }

  return smallAns;
}


int main()
{
    // int arr[5] = {2, 1, 3, 1, 4};
    // int x = 3;

    // // printUsingRec(arr, 5, 0);
    // // cout << endl;
    // // printUsingRec(arr, 5, 0);

    // vector<int> ans =  allIndices(arr, 5, 0, 1);

    int arr[6] = {1, 5, 4, 3, 6, 2};

    vector<vector<int>> ans = arraySumX(arr, 6, 0, 8);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << ", " << endl;
    }

    return 0;
}