/*
 * Problem #647: Palindromic Substrings
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 8/9/2026, 7:03:16 PM
 * Link: https://leetcode.com/problems/palindromic-substrings/
 */

class Solution {
public:
    int count(string &s, int offset){
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int l = i;
            int r = i + offset;

            while(l >= 0 && r < n && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int odd = count(s, 0);
        int even = count(s, 1);

        return even + odd;
    }
};
