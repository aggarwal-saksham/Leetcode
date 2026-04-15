/*
 * Problem #53: Maximum Subarray
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/10/2024, 2:24:29 PM
 * Link: https://leetcode.com/problems/maximum-subarray/
 */

class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
            int n = nums.size();
            int sum = 0;
            int max = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                sum += nums[i];

                if (sum > max){
                    max = sum;
                }

                if(sum < 0){
                    sum = 0;
                }

            }
            return max;
        }
};
