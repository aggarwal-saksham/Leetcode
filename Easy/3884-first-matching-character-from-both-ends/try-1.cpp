/*
 * Problem #3884: First Matching Character From Both Ends
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/31/2026, 7:11:09 PM
 * Link: https://leetcode.com/problems/first-matching-character-from-both-ends/
 */

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l <= r){
            if(s[l] == s[r]) return l;
            l++;
            r--;
        }
        return -1;
    }
};
