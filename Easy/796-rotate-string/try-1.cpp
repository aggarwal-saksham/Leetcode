/*
 * Problem #796: Rotate String
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/16/2024, 2:06:24 PM
 * Link: https://leetcode.com/problems/rotate-string/
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string s2;
        s2 = s.append(s);
        int pos = s2.find(goal);
        if (pos == string::npos) return false;
        return true;
        
    }
};
