/*
 * Problem #242: Valid Anagram
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/16/2024, 2:17:58 PM
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
