class Solution {
public:
    bool rec(int i, vector<int>& nums, int k, vector<vector<int>>& dp) {
        if(k == 0) return true;
        if(i == nums.size() || k < 0) return false;

        if(dp[i][k] != -1) return dp[i][k];

        bool take = rec(i + 1, nums, k - nums[i], dp);
        bool notake = rec(i + 1, nums, k, dp);

        return dp[i][k] = take || notake;
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return rec(0, arr, k, dp);
    }
};