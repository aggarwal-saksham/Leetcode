/*
 * Problem #132: Palindrome Partitioning II
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/6/2025, 11:12:59 PM
 * Link: https://leetcode.com/problems/palindrome-partitioning-ii/
 */

class Solution
{
    public:
    bool isPal(int i, int j, string &s) {
        
        while(i < j) {
            
            if(s[i] != s[j]) return false;
            
            i += 1;
            j -= 1;
            
        }
        
        return true;
        
    }
        int minCut(string s)
        {
            int n = s.length();
            vector<int> dp(n + 1, -1);
            dp[n] = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                int mini = INT_MAX;

                for (int j = i; j < n; j++)
                {
                    if (isPal(i, j, s))
                    {
                        int cost = 1 + dp[j + 1];
                        mini = min(mini, cost);
                    }
                }
                dp[i] = mini;
            }
            return dp[0] - 1;
        }
};
