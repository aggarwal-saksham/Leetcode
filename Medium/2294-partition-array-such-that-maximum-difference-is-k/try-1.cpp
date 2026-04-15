/*
 * Problem #2294: Partition Array Such That Maximum Difference Is K
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2025, 2:43:05 PM
 * Link: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
 */

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int mini = nums[0];
        for(int i = 1; i < n; i++){
            if(abs(nums[i] - mini) <= k) continue;
            else{
                mini = nums[i];
                cnt++;
            } 
        }

        return cnt;
    }
};
