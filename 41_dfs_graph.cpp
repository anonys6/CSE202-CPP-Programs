#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<int> arr[10];
bool vis[10];

void dfs(int sv) {

    cout << sv << " ";
    vis[sv] = true;

    for (int i = 0; i < arr[sv].size(); i++) {

        if (!vis[arr[sv][i]]) {
            dfs(arr[sv][i]);
        }
    }
}

int main() {

    cin >> v >> e;

    for (int i = 0; i < v; i++) {
        vis[i] = false;
    }

    for (int i = 0; i < e; i++) {
        int sv, ev;
        cin >> sv >> ev;

        arr[sv].push_back(ev);
        arr[ev].push_back(sv);
    }

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

// #include <iostream>

// using namespace std;

// int v, e;
// int arr[10][10];
// bool vis[10];

// void dfs(int sv) {
//     cout << sv << " ";
//     vis[sv] = true;

//     for (int i = 0; i < v; i++) {
//         if (arr[sv][i] == 1 && !vis[i]) {
//             dfs(i);
//         }
//     }
// }

// int main()
// {
//     cin >> v >> e;

//     for (int i = 0; i < v; i++) {
//         for (int j = 0; j < v; j++) {
//             vis[i] = false;
//             arr[i][j] = 0;
//         }
//     }

//     for (int i = 0; i < e; i++) {
//         int sv, ev;
//         cin >> sv >> ev;

//         arr[sv][ev] = 1;
//         arr[ev][sv] = 1;
//     }

//     dfs(0);

//     return 0;
// }
