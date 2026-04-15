/*
 * Problem #3659: Partition Array Into K-Distinct Groups
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/26/2025, 2:30:56 AM
 * Link: https://leetcode.com/problems/partition-array-into-k-distinct-groups/
 */

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;
        unordered_map<int, int> mpp;
        for(auto num : nums){
            mpp[num]++;
            if(mpp[num] > nums.size() / k) return false;
        }
        return true;
    }
};
