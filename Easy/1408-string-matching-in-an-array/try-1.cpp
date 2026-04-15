/*
 * Problem #1408: String Matching in an Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/7/2025, 8:29:40 PM
 * Link: https://leetcode.com/problems/string-matching-in-an-array/
 */

class Solution
{
    public:
        vector<string> stringMatching(vector<string> &words)
        {
            set<string> ans;
            for (int i = 0; i < words.size(); i++)
            {
                for (int j = 0; j < words.size(); j++)
                {
                    if (j == i) continue;
                    if (words[i].find(words[j]) != -1)
                    {
                        ans.insert(words[j]);
                    }
                }
            }
            return vector<string> (ans.begin(), ans.end());
        }
};
