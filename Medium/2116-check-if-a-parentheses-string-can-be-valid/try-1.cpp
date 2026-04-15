/*
 * Problem #2116: Check if a Parentheses String Can Be Valid
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/12/2025, 9:21:10 PM
 * Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
 */

class Solution
{
    public:
        bool canBeValid(string s, string locked)
        {
            int n = s.length();
            if (n % 2 != 0) return false;
            int bal = 0;
            for (int i = 0; i < n; i++)
            {
                if (locked[i] == '0' || s[i] == '(')
                    bal++;
                else
                    bal--;

                if (bal < 0) return false;
            }

            bal = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                if (locked[i] == '0' || s[i] == ')')
                    bal++;
                else
                    bal--;

                if (bal < 0) return false;
            }

            return true;
        }
};
