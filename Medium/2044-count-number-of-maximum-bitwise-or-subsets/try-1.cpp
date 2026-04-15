/*
 * Problem #2044: Count Number of Maximum Bitwise-OR Subsets
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/28/2025, 2:43:51 PM
 * Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
 */

class Solution {
public:
    int solve(vector<int> &nums, int &maxi, int orr, int idx, vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(orr == maxi) return 1;
            else return 0;
        }

        if(dp[idx][orr] != -1) return dp[idx][orr];

        int take = solve(nums, maxi, orr | nums[idx], idx + 1, dp);
        int notake = solve(nums, maxi, orr, idx + 1, dp);

        return dp[idx][orr] = take +notake;


    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int num : nums){
           maxi |= num;
        }

        vector<vector<int>> dp(nums.size() + 1, vector<int>(maxi + 1, -1));

        return         solve(nums, maxi, 0, 0, dp);

    }
};
