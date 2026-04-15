/*
 * Problem #171: Excel Sheet Column Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/21/2025, 12:38:31 AM
 * Link: https://leetcode.com/problems/excel-sheet-column-number/
 */

class Solution
{
    public:
        int titleToNumber(string columnTitle)
        {

            int n = columnTitle.length() - 1;
            int ans = 0;
            for (char c: columnTitle)
            {
                ans += (c - 'A' + 1) *pow(26, n);
                n--;
            }
            return ans;
        }
};
