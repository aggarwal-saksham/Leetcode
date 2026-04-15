/*
 * Problem #3811: Number of Alternating XOR Partitions
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/17/2026, 9:21:31 PM
 * Link: https://leetcode.com/problems/number-of-alternating-xor-partitions/
 */

class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        
        int n = nums.size();
        long long MOD = 1e9 + 7;
        
        
        vector<long long> dp(4, 0);
        
        
        int targets[4];
        targets[0] = target1;
        targets[1] = target1 ^ target2;
        targets[2] = target2;
        targets[3] = 0;

        int xorr = 0;
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
            
            vector<long long> next_dp(4, 0);
            
            for (int k = 0; k < 4; k++) {
                if (xorr == targets[k]) {
                    if (k == 0) {
                       next_dp[0] = (1 + dp[3]) % MOD;
                    } else {
                       next_dp[k] = dp[k - 1];
                    }
                }
            }
            
            for (int k = 0; k < 4; k++) {
                dp[k] = (dp[k] + next_dp[k]) % MOD;
            }

           
            if (i == n - 1) {
                long long result = 0;
                for (int k = 0; k < 4; k++) result = (result + next_dp[k]) % MOD;
                return (int)result;
            }
        }
        
        return 0;
    }
};
