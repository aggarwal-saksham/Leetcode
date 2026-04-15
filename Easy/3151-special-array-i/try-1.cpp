/*
 * Problem #3151: Special Array I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/1/2025, 12:59:06 PM
 * Link: https://leetcode.com/problems/special-array-i/
 */

class Solution
{
    public:
        bool isArraySpecial(vector<int> &nums)
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if ((nums[i] + nums[i + 1]) % 2 == 0) 
                return false;
            }
            return true;
        }
};
