#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int getMaxRemovals(const string &mainStr, int usedMask, vector<string> &subStrs, unordered_map<string, unordered_map<int, int>> &memo) {
    if (memo[mainStr].count(usedMask)) {
        return memo[mainStr][usedMask];
    }

    int maxRemovals = 0;

    for (vector<string>::size_type i = 0; i < subStrs.size(); ++i) {
        if (!(usedMask & (1 << i))) {
            const string &subStr = subStrs[i];
            size_t pos = mainStr.find(subStr);

            while (pos != string::npos) {
                string newStr = mainStr.substr(0, pos) + mainStr.substr(pos + subStr.length());
                int newUsedMask = usedMask | (1 << i);
                int removals = 1 + getMaxRemovals(newStr, newUsedMask, subStrs, memo);

                if (removals > maxRemovals) {
                    maxRemovals = removals;
                }

                pos = mainStr.find(subStr, pos + 1);
            }
        }
    }

    memo[mainStr][usedMask] = maxRemovals;
    return maxRemovals;
}

int main() {
    int numSubStrs;
    cin >> numSubStrs;

    vector<string> subStrs(numSubStrs);
    for (int i = 0; i < numSubStrs; ++i) {
        cin >> subStrs[i];
    }

    string mainStr;
    cin >> mainStr;

    unordered_map<string, unordered_map<int, int>> memo;
    int result = getMaxRemovals(mainStr, 0, subStrs, memo);

    cout << result << endl;

    return 0;
}