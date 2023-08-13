
lass Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> common;
        if (words.empty())
        {
            return common;
        }

        vector<int> minCharCount(26, INT_MAX);

        for (const string &word : words)
        {
            vector<int> charCount(26, 0);
            for (char c : word)
            {
                charCount[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i)
            {
                minCharCount[i] = min(minCharCount[i], charCount[i]);
            }
        }

        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < minCharCount[i]; ++j)
            {
                common.push_back(string(1, 'a' + i));
            }
        }

        return common;
    }
};