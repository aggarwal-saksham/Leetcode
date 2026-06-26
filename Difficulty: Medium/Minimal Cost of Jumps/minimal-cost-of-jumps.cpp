class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i = 1; i < n; i++){
            int mini = INT_MAX;
            for(int j = 1; j <= k; j++){
                if(i < j) break;
                 mini = min(mini, dp[i - j] + abs(arr[i] - arr[i - j]));
            }
            dp[i] = mini;
        }
        return dp[n - 1];
    }
};