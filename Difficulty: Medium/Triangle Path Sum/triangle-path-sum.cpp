class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        int m = triangle[i].size();

        if(dp[i][j] != -1) return dp[i][j];

        if(i >= n || j >= m) return 1e9;
        if(i == n - 1) return triangle[i][j];

        int diag = triangle[i][j] + rec(i + 1, j + 1, triangle, dp);
        int down = triangle[i][j] + rec(i + 1, j, triangle, dp);

        return dp[i][j] = min(diag, down); 
    }
    int minPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(0, 0, triangle, dp);


    }
};