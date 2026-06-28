
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int rec(int W, vector<int> &val, vector<int> &wt, int i, vector<vector<int>> &dp) {
        
        if(i < 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        int take = -1e9;
        if(wt[i] <= W)
            take = val[i] + rec(W - wt[i], val, wt, i - 1, dp);
        
        int notTake = rec(W, val, wt, i - 1, dp);
        
        return dp[i][W] = max(take, notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return rec(W, val, wt, n - 1, dp);
        
    }
};

