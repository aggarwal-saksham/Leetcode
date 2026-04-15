/*
 * Problem #1423: Maximum Points You Can Obtain from Cards
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/3/2025, 3:12:03 PM
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
            
            int leftSum = 0, rightSum = 0, maxSum = 0;
            for (int i = 0; i < k; i++)
            {
                leftSum += cardPoints[i];
            }
            ans = leftSum;
            for(int i = n - 1; i >= n - k; i--){
                rightSum += cardPoints[i];
                leftSum -= cardPoints[i - n + k];
                ans = max(ans, leftSum + rightSum);
            }
            return ans;
        }
};
