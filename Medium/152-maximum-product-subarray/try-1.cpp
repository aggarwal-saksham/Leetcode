/*
 * Problem #152: Maximum Product Subarray
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/30/2024, 11:23:05 PM
 * Link: https://leetcode.com/problems/maximum-product-subarray/
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double pre = 1, suf = 1;
        double maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;

            pre *= nums[i];
            suf *= nums[n - i - 1];
            maxi = max({maxi,pre,suf});
        }
        return maxi;
    }
};
