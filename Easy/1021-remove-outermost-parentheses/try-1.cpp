/*
 * Problem #1021: Remove Outermost Parentheses
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/2/2024, 10:27:51 PM
 * Link: https://leetcode.com/problems/remove-outermost-parentheses/
 */

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
    int openCount = 0;

    for (char c : s) {
        if (c == '(') {
            if (openCount > 0) {
                result += c;
            }
            openCount++;
        } else {
            openCount--;
            if (openCount > 0) {
                result += c;
            }
        }
    }

    return result;
    }
};
