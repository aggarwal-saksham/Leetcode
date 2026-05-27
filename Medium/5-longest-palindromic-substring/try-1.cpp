/*
 * Problem #5: Longest Palindromic Substring
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 7:35:42 PM
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 */

class Solution {
public:

    string helper(string &s, bool flag){

        int n = s.size();
        int maxLen = 0;
        string ans = "";

        for(int i = 0; i < n; i++){

            int l = i;
            int r = (flag) ? i + 1 : i;

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

        string odd = helper(s, false);
        string even = helper(s, true);

        return (even.length() > odd.length()) ? even : odd;
    }
};
