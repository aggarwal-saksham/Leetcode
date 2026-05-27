/*
 * Problem #209: Minimum Size Subarray Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/14/2026, 3:09:38 PM
 * Link: https://leetcode.com/problems/minimum-size-subarray-sum/
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int total = 0,ans = INT_MAX, n = nums.size();
        while(r < n){
            total += nums[r];
            while(total >= target){
                ans = min(ans, r - l + 1);
                total -= nums[l];
                l++;
            }
            // if(total >= target) ans = min(ans, r - l + 1);
            r++;

        }
        return ans == INT_MAX ? 0 : ans;
    }
};
