/*
 * Problem #5: Longest Palindromic Substring
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/20/2026, 3:05:22 PM
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 */

class Solution {
public:

    string helper(string &s, int add){

        int n = s.size();
        int maxLen = 0;
        string ans = "";

        for(int i = 0; i < n; i++){

            int l = i;
            int r = i + add;

            while(l >= 0 && r < n && s[l] == s[r]){

                if((r - l + 1) > maxLen){
                    maxLen = r - l + 1;
                    ans = s.substr(l, maxLen);
                }

                l--;
                r++;
            }
        }

        return ans;
    }

    string longestPalindrome(string s) {

        if(s.size() == 1)
            return s;

        string odd = helper(s, 0);
        string even = helper(s, 1);

        return (even.length() > odd.length()) ? even : odd;
    }
};
