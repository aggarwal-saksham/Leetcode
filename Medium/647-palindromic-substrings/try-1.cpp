/*
 * Problem #647: Palindromic Substrings
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 2:21:51 AM
 * Link: https://leetcode.com/problems/palindromic-substrings/
 */

class Solution {
public:
    bool isPalindrome(string s){

    int l = 0;
    int r = s.length() - 1;

    while(l < r){

        if(s[l] != s[r])
            return false;

        l++;
        r--;
    }

    return true;
}
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s.substr(i, j - i + 1))) cnt++;
            }
        }
        return cnt;
    }
};
