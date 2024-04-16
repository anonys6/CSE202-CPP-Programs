#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> commonChars(vector<string> &words) {
        vector<string> common;
        if (words.empty()) {
            return common;
        }

        vector<int> minCharCount(26, INT_MAX);

        for (const string &word : words) {
            vector<int> charCount(26, 0);
            for (char c : word) {
                charCount[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minCharCount[i] = min(minCharCount[i], charCount[i]);
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (minCharCount[i] != INT_MAX) {
                for (int j = 0; j < minCharCount[i]; ++j) {
                    common.push_back(string(1, 'a' + i));
                }
            }
        }

        return common;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"bella", "label", "roller"};
    vector<string> commonChars = solution.commonChars(words);

    cout << "Common characters: ";
    for (const string &commonChar : commonChars) {
        cout << commonChar << " ";
    }
    cout << endl;

    return 0;
}