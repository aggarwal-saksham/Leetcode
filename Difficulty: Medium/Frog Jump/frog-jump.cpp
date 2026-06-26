class Solution {
  public:
    // int solve(vector<int>& height, int n, vector<int> &dp){
    //     if(n == 0) return 0;
    //     if(n == 1) return abs(height[1] - height[0]);
        
    //     if(dp[n] != -1) return dp[n];
        
    //     return dp[n] = min(solve(height, n - 2, dp) + abs(height[n] - height[n - 2]), 
    //                       solve(height, n - 1, dp) + abs(height[n] - height[n - 1]));
    // }
    int minCost(vector<int>& height) {
        // Code here
        
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i = 1; i < n; i++){
            int c1 = dp[i - 1] + abs(height[i] - height[i - 1]);
            int c2 = INT_MAX;
            if(i > 1)  c2 = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(c1, c2);
        }
        return dp[n - 1];
        
        
    }
};