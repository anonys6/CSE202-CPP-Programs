#include <string>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<string> result;
        vector<int> left(26, 0), right(26, 0);

        for (int i = 0; i < s.length(); i++) {
            right[s[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            right[s[i] - 'a']--;

            for (int j = 0; j < 26; j++) {
                if (left[j] > 0 && right[j] > 0) {
                    string palindrome = string(1, 'a' + j) + s[i] + string(1, 'a' + j);
                    result.insert(palindrome);
                }
            }
            
            left[s[i] - 'a']++;
        }

        return result.size();
    }
};
