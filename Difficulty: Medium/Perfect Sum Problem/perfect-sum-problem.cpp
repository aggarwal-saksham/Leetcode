class Solution {
  public:
    int perfectSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+ 1, 0));
        
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        if (arr[0] <= sum) {
            dp[0][arr[0]] += 1;
        }
        
        for(int i = 1; i < n; i++){
            //start j from 0 coz 
            //((0,x) and (x) are two diff subsets)
            //ignore sheet
            for(int j = 0; j <= sum; j++){
                int notake = dp[i - 1][j];
                
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i - 1][j - arr[i]];
                }
                
                dp[i][j] = take + notake;
            }
        }
        
        return dp[n - 1][sum];
    }
};