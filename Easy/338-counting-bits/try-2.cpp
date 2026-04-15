/*
 * Problem #338: Counting Bits
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/15/2026, 11:05:19 PM
 * Link: https://leetcode.com/problems/counting-bits/
 */

class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};
