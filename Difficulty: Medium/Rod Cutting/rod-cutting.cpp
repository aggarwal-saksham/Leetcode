class Solution {
public:
    int rec(int len, vector<int> &price, int i, vector<vector<int>> &dp){
        if(i < 0) return 0;

        if(dp[i][len] != -1) return dp[i][len];

        int take = 0;
        if(i + 1 <= len)
            take = price[i] + rec(len - (i + 1), price, i, dp);

        int notTake = rec(len, price, i - 1, dp);

        return dp[i][len] = max(take, notTake);
    }

    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(n, price, n - 1, dp);
    }
};