/*
 * Problem #3174: Clear Digits
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/10/2025, 2:42:44 PM
 * Link: https://leetcode.com/problems/clear-digits/
 */

class Solution
{
    public:
        string clearDigits(string s)
        {
            string ans = "";
            for (char c: s)
            {
                if (isalpha(c)) ans += c;
                else if (isdigit(c)) ans.pop_back();
            }
            return ans;
        }
};
