/*
 * Problem #647: Palindromic Substrings
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 2:30:47 AM
 * Link: https://leetcode.com/problems/palindromic-substrings/
 */

class Solution {
public:
    
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();

        for(int flag = 0; flag <= 1; flag++){

            for(int i = 0; i < n; i++){

                int l = i;
                int r = (flag) ? i + 1 : i;

                while(l >= 0 && r < n && s[l] == s[r]){

                    cnt++;

                    l--;
                    r++;
                }
            }
        }

        return cnt;
    }
};
