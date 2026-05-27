/*
 * Problem #796: Rotate String
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 12:46:59 AM
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
