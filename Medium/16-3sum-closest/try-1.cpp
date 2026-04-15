/*
 * Problem #16: 3Sum Closest
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 1:48:42 PM
 * Link: https://leetcode.com/problems/3sum-closest/
 */

class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());

            int mini = INT_MAX;
            int ans = 0;
           	//-4 -1 -1 0 1 2
            for (int i = 0; i < nums.size() - 2; i++)
            {

                int j = i + 1;
                int k = nums.size() - 1;

                while (j < k)
                {

                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = abs(target - sum);

                    if (diff < mini)
                    {
                        mini = diff;
                        ans = sum;
                    }
                    if (sum < target)
                    {
                        j++;
                    }
                    else if (sum > target)
                    {
                        k--;
                    }
                    else
                    {
                        return target;
                    }
                }
            }

            return ans;
        }
};
