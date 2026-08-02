/*
 * Problem #4010: Maximize Pair Strength Using GCD
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/2/2026, 2:48:53 PM
 * Link: https://leetcode.com/problems/maximize-pair-strength-using-gcd/
 */

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long long x = nums[i];
                long long y = nums[j];
                ans = max(ans, 
                          (long long)lcm(x, y) /                                
                          (long long)gcd(x, y)
                         );
            }
        }
        return ans;
    }
};
