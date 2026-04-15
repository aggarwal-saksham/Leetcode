/*
 * Problem #1423: Maximum Points You Can Obtain from Cards
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/3/2025, 2:45:49 PM
 * Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 */

class Solution
{
    public:
        int maxScore(vector<int> &cardPoints, int k)
        {
            int n = cardPoints.size();
            int l = 0, r = n - k - 1;
            int ans = 0;
            int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
            int currSum = 0;
            for (int i = 0; i < n - k; i++)
            {
                currSum += cardPoints[i];
            }
            while (r < n - 1)
            {
                ans = max(ans, total - currSum);
                r++;
                currSum += cardPoints[r];
                currSum -= cardPoints[l];
                l++;
            }
            ans = max(ans, total - currSum);
            return ans;
        }
};
