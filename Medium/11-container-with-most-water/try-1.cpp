/*
 * Problem #11: Container With Most Water
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/18/2025, 4:14:38 PM
 * Link: https://leetcode.com/problems/container-with-most-water/
 */

class Solution
{
    public:
        int maxArea(vector<int> &height)
        {
            int n = height.size(), maxi = 0;
            int l = 0, r = n - 1;
            while (l < n && r >= 0 && l != r)
            {
                maxi = max(maxi, abs(l - r) *min(height[l], height[r]));
                if (height[l] > height[r]) r--;
                else if (height[l] < height[r]) l++;
                else
                {
                    l++;
                    r--;
                }
            }
            return maxi;
        }
};
