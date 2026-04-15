/*
 * Problem #930: Binary Subarrays With Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2025, 11:52:27 PM
 * Link: https://leetcode.com/problems/binary-subarrays-with-sum/
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mpp;
        int sum = 0, cnt = 0;
        mpp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum - goal;
            cnt += mpp[rem];
            mpp[sum] += 1;
        }
        return cnt;
    }
};
