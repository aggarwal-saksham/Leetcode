/*
 * Problem #3794: Reverse String Prefix
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/4/2026, 2:43:03 PM
 * Link: https://leetcode.com/problems/reverse-string-prefix/
 */

class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.length();
        string x = s.substr(0, k);
        reverse(x.begin(), x.end());
        string y = s.substr(k, n - k);
        return (x + y);
        
    }
};
