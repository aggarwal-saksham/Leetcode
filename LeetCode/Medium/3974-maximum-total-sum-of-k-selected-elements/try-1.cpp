/*
 * Problem #3974: Maximum Total Sum of K Selected Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2026, 6:55:20 PM
 * Link: https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
 */

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int i = 0;
        while(i < n && k--){
            ans += nums[i] * 1LL * mul;
            if(mul >1 ){
                mul--;
            }
            i++;
        }
        return ans;
    }
};
