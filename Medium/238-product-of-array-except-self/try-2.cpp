/*
 * Problem #238: Product of Array Except Self
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 3/19/2025, 6:31:21 PM
 * Link: https://leetcode.com/problems/product-of-array-except-self/
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long pre = 1, post = 1;
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            ans[i] *= pre;
            pre *= nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
           ans[i] *= post;
           post *= nums[i];
        }
       
        return ans;
    }
};

