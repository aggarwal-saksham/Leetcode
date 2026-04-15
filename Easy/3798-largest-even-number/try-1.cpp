/*
 * Problem #3798: Largest Even Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/5/2026, 1:51:28 PM
 * Link: https://leetcode.com/problems/largest-even-number/
 */

class Solution {
public:
    string largestEven(string s) {
        int n = s.length();
        int ptr = n;
        int i = n - 1;
        while(i >= 0 && s[i] != '2'){
            
            ptr = i;
            i--;
        }
        if(i >= 0 && s[i] != '2') i--;
        return (s.substr(0, ptr) == "1") ? "" : s.substr(0, ptr);
    }
};
