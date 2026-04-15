/*
 * Problem #242: Valid Anagram
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 12/28/2025, 11:34:14 PM
 * Link: https://leetcode.com/problems/valid-anagram/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};
