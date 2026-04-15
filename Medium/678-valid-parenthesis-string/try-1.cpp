/*
 * Problem #678: Valid Parenthesis String
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/2/2025, 3:13:18 PM
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 */

class Solution
{
    public:
       	//"(**(*()**()**((**(*)"
        bool checkValidString(string s)
        {
            int n = s.length();
            int min = 0, max = 0;
            for (char c: s)
            {
                if (c == '(')
                {
                    min++;
                    max++;
                }
                else if (c == ')')
                {
                    min--;
                    max--;
                }
                else
                {
                    min--;
                    max++;
                }
                if (min < 0) min = 0;
                if (max < 0) return false;
            }
            return (!min);
        }
};
