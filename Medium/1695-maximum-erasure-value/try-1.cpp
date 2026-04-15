/*
 * Problem #1695: Maximum Erasure Value
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/22/2025, 2:18:40 PM
 * Link: https://leetcode.com/problems/maximum-erasure-value/
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        int sum = 0;
        int maxi = 0;
        while(l < n && r < n){
            while( r < n && mpp.find(nums[r]) == mpp.end()){
                mpp[nums[r]]++;
                sum += nums[r];
                maxi = max(maxi, sum);
                r++;
            }
            
            if(r < n && mpp.find(nums[r]) != mpp.end()){
                while(l < r && nums[l] != nums[r]){
                    mpp.erase(nums[l]);
                    sum -= nums[l];
                    l++;
                }
                mpp.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
        }
        return maxi;
    }
};
