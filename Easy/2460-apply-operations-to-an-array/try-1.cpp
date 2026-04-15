/*
 * Problem #2460: Apply Operations to an Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/9/2025, 1:49:52 PM
 * Link: https://leetcode.com/problems/apply-operations-to-an-array/
 */

class Solution
{
    public:
        vector<int> applyOperations(vector<int> &nums)
        {
           	//14033200
            int n = nums.size();
            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] != 0)
                {
                    swap(nums[i], nums[j]);
                    j++;
                }
            }
            return nums;
        }
};
