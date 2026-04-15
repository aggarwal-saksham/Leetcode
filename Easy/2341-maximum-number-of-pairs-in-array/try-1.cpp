/*
 * Problem #2341: Maximum Number of Pairs in Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/14/2026, 3:58:07 PM
 * Link: https://leetcode.com/problems/maximum-number-of-pairs-in-array/
 */

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        int pairs = 0, left = 0;
        for(auto it : mpp){
            pairs += it.second / 2;
            left += it.second % 2;
        }

        return {pairs, left};
    }
};
