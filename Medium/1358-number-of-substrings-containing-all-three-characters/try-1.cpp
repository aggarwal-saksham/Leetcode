/*
 * Problem #1358: Number of Substrings Containing All Three Characters
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2025, 5:40:07 PM
 * Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int a = -1, b = -1, c = -1;
        int cnt = 0;
        int r = 0;
        while (r < n) {
            if (s[r] == 'a')
                a = r;
            else if (s[r] == 'b')
                b = r;
            else if (s[r] == 'c')
                c = r;

            if (a >= 0 && b >= 0 && c >= 0) {
                int mini = min({a, b, c});

                cnt += mini + 1;
            }
            r++;
        }
        return cnt;
    }
};
