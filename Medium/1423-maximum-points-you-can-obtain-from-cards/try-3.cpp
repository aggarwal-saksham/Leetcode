/*
 * Problem #1423: Maximum Points You Can Obtain from Cards
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 12/20/2025, 2:06:20 PM
 * Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 */

class Solution
{
    public:
        int maxScore(vector<int> &nums, int k)
        {
            int n = nums.size();
            int mini = INT_MAX, sum = 0;
            
            int l = 0, r = n - k - 1;
            for(int i = l; i <= r; i++){
                sum += nums[i];

            }
            mini = min(mini, sum);
            while(r < n - 1){
                r++;
                sum -= nums[l];
                sum += nums[r];
                l++;
                mini = min(mini, sum);

            }
            return accumulate(nums.begin(), nums.end(), 0) - mini;
        }
};
