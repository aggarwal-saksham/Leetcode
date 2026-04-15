/*
 * Problem #3853: Merge Close Characters
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/28/2026, 8:25:09 PM
 * Link: https://leetcode.com/problems/merge-close-characters/
 */

class Solution {
public:
    string mergeCharacters(string s, int k) {
        while (true) {
            bool merged = false;
            int n = s.size();

            for (int l = 0; l < n; l++) {
                for (int r = l + 1; r < n && (r - l) <= k; r++) {
                    if (s[l] == s[r]) {
                        s.erase(r, 1);
                        merged = true;
                        break;
                    }
                }
                if (merged) break;
            }

            if (!merged) break;
        }

        return s;
    }
};
