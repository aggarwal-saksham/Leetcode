/*
 * Problem #4030: Check ASCII Palindromic
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/29/2026, 3:21:29 PM
 * Link: https://leetcode.com/problems/check-ascii-palindromic/
 */

class Solution {
public:
    bool isPalindromic(string s) {
        string ans = "";
        for(char c : s){
            int n = c - 'a' + 97;
            bitset<8> binary8(n);
            ans += binary8.to_string();
        }
        for(int i = 0; i < ans.size()/ 2; i++){
            if(ans[i] != ans[ans.size() - i - 1]) return false;
        }
        
        return true;
    }
};
