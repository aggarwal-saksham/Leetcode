class Solution {
  public:
    int rec(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i; k <= j -1; k++){
            int curr = arr[i - 1] * arr[k] * arr[j];
            mini = min(mini, curr + rec(i, k, arr, dp)
            + rec(k + 1, j, arr, dp));
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        // code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(1, n - 1, arr, dp);
        
    }
};