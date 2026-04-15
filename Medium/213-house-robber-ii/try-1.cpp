/*
 * Problem #213: House Robber II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/15/2025, 2:27:33 PM
 * Link: https://leetcode.com/problems/house-robber-ii/
 */

class Solution
{
    public:
        int rec(vector<int> &nums, int n, vector<int> &t)
        {
            if (n <= 0) return 0;
            if (t[n] != -1) return t[n];
            return t[n] = max(nums[n - 1] + rec(nums, n - 2, t), rec(nums, n - 1, t));
        }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> num1(nums.begin(), nums.end() - 1); 
        vector<int> num2(nums.begin() + 1, nums.end()); 

        vector<int> t1(num1.size() + 1, -1);
        vector<int> t2(num2.size() + 1, -1);
        
        return max(rec(num1, num1.size(), t1), rec(num2, num2.size(), t2));
    }
};
