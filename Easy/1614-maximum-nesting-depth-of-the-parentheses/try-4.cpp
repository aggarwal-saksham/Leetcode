/*
 * Problem #1614: Maximum Nesting Depth of the Parentheses
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 3:03:21 PM
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 */

class Solution {
public:
    int maxDepth(string s) {
        int open = 0, ans = 0;
        for (char c : s) {
            if (c == '(')
                open++;

            else if (c == ')')
                open--;

            ans = max(ans, open);
        }
        return ans;
    }
};
