/*
 * Problem #242: Valid Anagram
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/16/2024, 2:15:15 PM
 * Link: https://leetcode.com/problems/valid-anagram/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for (char c : s) {
            if (smap.find(c) == smap.end()) {
                smap[c] = 1; // First occurrence
            } else {
                smap[c]++; // Increment frequency
            }
        }

        for (char c : t) {
            if (tmap.find(c) == tmap.end()) {
                tmap[c] = 1; // First occurrence
            } else {
                tmap[c]++; // Increment frequency
            }
        }
        for (const auto& pair : smap) {
        // Check if the key exists in the second map and has the same value
        auto it = tmap.find(pair.first);
        if (it == tmap.end() || it->second != pair.second) {
            return false;
        }
    }

    // All checks passed, the maps are identical
    return true;
    }
};
