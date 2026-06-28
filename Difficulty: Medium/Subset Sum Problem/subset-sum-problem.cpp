class Solution {
  public:
     bool rec(int i, vector<int> &arr, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i < 0 || target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = rec(i - 1, arr, target - arr[i], dp) ||
                            rec(i - 1, arr, target, dp);
    }
    bool isSubsetSum(vector<int>& arr, int k) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
        return rec(arr.size() - 1, arr, k, dp);
    }
};