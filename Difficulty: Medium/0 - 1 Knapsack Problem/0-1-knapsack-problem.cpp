
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int rec(int W, vector<int> &val, vector<int> &wt, int i, vector<vector<int>> &dp) {
        
        if(W < 0) return -1e9;
        if(i < 0) return 0;
        if(dp[i][W] != -1) return dp[i][W];
        
        return dp[i][W] = max(val[i] + rec(W-wt[i], val, wt, i-1, dp),
            rec(W, val, wt, i-1, dp));
        
        
       
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return rec(W, val, wt, n - 1, dp);
        
    }
};

