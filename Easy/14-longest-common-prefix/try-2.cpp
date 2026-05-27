/*
 * Problem #14: Longest Common Prefix
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 12:13:00 AM
 * Link: https://leetcode.com/problems/longest-common-prefix/
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string base = strs[0];
        for(int i = 0; i < base.size(); i++){
            char c = base[i];
            for(string s : strs){
                if(i > s.size() || s[i] != c){
                    return s.substr(0, i);
                }
            }
        }
        return base;
    }
};
