/*
 * Problem #238: Product of Array Except Self
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/19/2025, 6:11:09 PM
 * Link: https://leetcode.com/problems/product-of-array-except-self/
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long pre = 1, post = 1;
        vector<int> ans(n), preProduct(n), postProduct(n);
        for (int i = 0; i < n; i++) {
            pre *= nums[i];
            preProduct[i] = pre;
        }
        for (int i = n - 1; i >= 0; i--) {
            post *= nums[i];
            postProduct[i] = post;
        }
        ans[0] = postProduct[1];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = preProduct[i - 1] * postProduct[i + 1];
        }
        ans[n - 1] = preProduct[n - 2];
        return ans;
    }
};

