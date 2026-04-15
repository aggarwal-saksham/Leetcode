/*
 * Problem #2942: Find Words Containing Character
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/26/2025, 11:49:50 PM
 * Link: https://leetcode.com/problems/find-words-containing-character/
 */

class Solution
{
    public:
        vector<int> findWordsContaining(vector<string> &words, char x)
        {
            int n = words.size();
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < words[i].length(); j++)
                {
                    if (words[i][j] == x)
                    {
                        ans.push_back(i);
                        break;
                    }
                }
            }
            return ans;
        }
};
