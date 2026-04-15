/*
 * Problem #2270: Number of Ways to Split Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/3/2025, 11:26:36 PM
 * Link: https://leetcode.com/problems/number-of-ways-to-split-array/
 */

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long rightSum = total - nums[0];
        long long currSum = nums[0];
        long long cnt = 0;
        if(currSum >= rightSum) cnt++;
        long long i = 1;
        while(i < n - 1){
            currSum += nums[i];
            rightSum -= nums[i];
            if(currSum >= rightSum) cnt++;
            i++;

        }
        return cnt;
    }
};
