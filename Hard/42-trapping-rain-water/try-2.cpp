/*
 * Problem #42: Trapping Rain Water
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/1/2026, 9:56:37 PM
 * Link: https://leetcode.com/problems/trapping-rain-water/
 */

class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            vector<int> prefix(n);
            vector<int> sufix(n);
            int ans = 0;

            prefix[0] = height[0];
            for (int i = 1; i < n; i++)
            {
                prefix[i] = max(prefix[i - 1], height[i]);
            }

            sufix[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                sufix[i] = max(sufix[i + 1], height[i]);
            }

            for (int i = 0; i < n; i++)
            {
                // if (prefix[i] >= height[i] && height[i] <= sufix[i])
                // {
                
                    int x =  min(prefix[i], sufix[i]) - height[i];
                    if(x > 0) ans += x;
                //}
            }

            return ans;
        }
};
