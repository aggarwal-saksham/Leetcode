/*
 * Problem #3867: Sum of GCD of Formed Pairs
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/16/2026, 12:57:04 PM
 * Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 */

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD(n);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            prefixGCD[i] = gcd(nums[i], maxi);
        }
        sort(prefixGCD.begin(), prefixGCD.end());
        long long ans = 0;
        for(int i = 0; i < n / 2; i++){
            ans += 0LL + gcd(prefixGCD[i], prefixGCD[n - i - 1]);
        }
        return ans;
    }
};
