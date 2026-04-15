/*
 * Problem #219: Contains Duplicate II
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/26/2025, 6:35:19 PM
 * Link: https://leetcode.com/problems/contains-duplicate-ii/
 */

class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {
            unordered_map<int, int> mpp;
            for (int i = 0; i < nums.size(); i++)
            {
                if (mpp.find(nums[i]) != mpp.end())
                {
                    if (abs(i - mpp[nums[i]]) <= k)
                        return true;
                }
                mpp[nums[i]] = i;
            }
            return false;
        }
};
