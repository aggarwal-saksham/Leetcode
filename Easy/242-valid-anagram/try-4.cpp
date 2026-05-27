/*
 * Problem #242: Valid Anagram
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 12:30:22 AM
 * Link: https://leetcode.com/problems/valid-anagram/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};
