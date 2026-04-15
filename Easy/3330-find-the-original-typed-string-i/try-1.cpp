/*
 * Problem #3330: Find the Original Typed String I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/1/2025, 1:04:54 PM
 * Link: https://leetcode.com/problems/find-the-original-typed-string-i/
 */

class Solution
{
    public:
        int possibleStringCount(string word)
        {
           	// aabbba
            int ans = 1;
            int cnt = 0;
            for (int i = 1; i < word.size(); i++)
            {
                if (word[i] == word[i - 1])
                {
                    cnt++;
                }
                else
                {
                    ans += cnt;
                    cnt = 0;
                }
            }
            ans += cnt;
            return ans;
        }
};
