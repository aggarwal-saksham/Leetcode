/*
 * Problem #796: Rotate String
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 11/3/2024, 1:59:55 PM
 * Link: https://leetcode.com/problems/rotate-string/
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string s2;
        s2 = s.append(s);
        int pos = s2.find(goal);
        if (pos == -1) return false;
        return true;
        
    }
};
