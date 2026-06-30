/*
 * Problem #1358: Number of Substrings Containing All Three Characters
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 5:22:55 PM
 * Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int a = -1, b = -1, c = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b')
                b = i;
            else
                c = i;

            if (a >= 0 && b >= 0 && c >= 0) {
                cnt += min({a, b, c}) + 1;
            }
        }
        return cnt;
    }
};
