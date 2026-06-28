class Solution {
  public:
       int rec(int i, vector<int> &arr, int target, vector<vector<int>> &dp){
        if(i < 0){
            return target == 0;
        }
        if(target < 0) return 0;

        if(dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = rec(i - 1, arr, target - arr[i], dp) +
                            rec(i - 1, arr, target, dp);
    }

    int perfectSum(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
        return rec(arr.size() - 1, arr, k, dp);
    }
};