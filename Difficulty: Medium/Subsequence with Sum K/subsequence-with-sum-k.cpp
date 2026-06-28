class Solution {
public:
    bool rec(int i, vector<int> &arr, int k, int sum, vector<vector<int>> &dp){
        if(sum == k) return true;
        if(i == arr.size() || sum > k) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        return dp[i][sum] = rec(i + 1, arr, k, sum + arr[i], dp) ||
                            rec(i + 1, arr, k, sum, dp);
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
        return rec(0, arr, k, 0, dp);
    }
};