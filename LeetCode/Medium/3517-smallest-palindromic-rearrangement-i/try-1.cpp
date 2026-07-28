/*
 * Problem #3517: Smallest Palindromic Rearrangement I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/28/2026, 2:42:39 PM
 * Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<int, int> freq;
        for(char c : s){
            freq[c - 'a']++;
        }

        string ans(n, ' ');
        int l = 0, r = n - 1;
        int oddChar;
        for(auto it : freq){
            int c = it.first;
            int f = it.second;
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
