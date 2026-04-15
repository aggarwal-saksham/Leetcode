/*
 * Problem #2206: Divide Array Into Equal Pairs
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/17/2025, 7:54:43 PM
 * Link: https://leetcode.com/problems/divide-array-into-equal-pairs/
 */

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        //int pairs = nums.size()/2;
        for(auto it : freq){
            if(it.second % 2 != 0) return false;
        }
        return true;
    }
};
