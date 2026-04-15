/*
 * Problem #3042: Count Prefix and Suffix Pairs I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/8/2025, 6:23:03 PM
 * Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/
 */

class Solution
{
    public:
        bool isPrefixAndSuffix(string str1, string str2)
        {
            if (str1 != str2.substr(0, str1.length()))
                return false;
            else
            {
                if (str1 != str2.substr(str2.length() - str1.length()))
                    return false;
            }
            return true;
        }
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                bool flag = isPrefixAndSuffix(words[i], words[j]);
                if (flag) cnt++;
            }
        }
        return cnt;
    }
};
