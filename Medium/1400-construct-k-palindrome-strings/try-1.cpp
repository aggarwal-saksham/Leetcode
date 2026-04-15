/*
 * Problem #1400: Construct K Palindrome Strings
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/11/2025, 6:29:49 PM
 * Link: https://leetcode.com/problems/construct-k-palindrome-strings/
 */

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return false;
        unordered_map<char, int> mpp;
        for(char c : s){
            mpp[c]++;
        }
        int cnt = 0;
        for(auto i : mpp){
            if(i.second % 2 != 0) cnt++;
        }
        if(cnt > k) return false;
        return true;

    }
};
