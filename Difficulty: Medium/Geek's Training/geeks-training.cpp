class Solution {
  public:
    int rec(int i, vector<vector<int>>& mat, int act, vector<vector<int>> &dp){
        if(i == mat.size()) return 0;
        if(dp[i][act] != -1) return dp[i][act];
        int r = 0, f = 0, l = 0;
        if(act != 0)  r = mat[i][0] + rec(i + 1, mat,  0, dp);
        if(act != 1)  f = mat[i][1] + rec(i + 1, mat, 1, dp);
        if(act != 2)  l = mat[i][2] + rec(i + 1, mat, 2, dp);
        return dp[i][act] = max({r, f, l});
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>> dp(mat.size(), vector<int>(4, -1));
        return rec(0, mat, 3, dp);
        
    }
};