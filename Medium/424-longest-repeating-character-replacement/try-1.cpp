/*
 * Problem #424: Longest Repeating Character Replacement
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2025, 11:05:40 PM
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int l = 0, r = 0;
        int maxi = k;
        while (r < n) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            if ((r - l + 1) - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};
