/*
 * Problem #3517: Smallest Palindromic Rearrangement I
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/28/2026, 3:08:11 PM
 * Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26);
        for(char c : s){
            freq[c - 'a']++;
        }

        string ans(n, ' ');
        int l = 0, r = n - 1;
        int oddChar;
        for(int i = 0; i < 26; i++){
            int c = i;
            int f = freq[i];
            if(f % 2 == 1){
                oddChar = c;
                f--;
            }
            while(f){
                ans[l] = c + 'a';
                l++;
                ans[r] = c + 'a';
                r--;
                f -= 2;
            }
        }
        if(l <= r){
            ans[l] = oddChar + 'a';
        }
        return ans;
    }
};
