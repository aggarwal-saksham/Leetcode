/*
 * Problem #1781: Sum of Beauty of All Substrings
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/9/2025, 6:00:54 PM
 * Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
 */

class Solution
{
    public:
        int beautySum(string s)
        {
            int n = s.length();
            vector<string> subs;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {

                unordered_map<char, int> mpp;
                for (int j = i; j < n; j++)

                {
                    mpp[s[j]]++;

                    int mini = INT_MAX, maxi = INT_MIN;
                    for (auto it: mpp)
                    {
                        mini = min(it.second, mini);
                        maxi = max(it.second, maxi);
                    }
                    if (maxi - mini > 0) ans += maxi - mini;
                }
            }
            return ans;
        }
};
