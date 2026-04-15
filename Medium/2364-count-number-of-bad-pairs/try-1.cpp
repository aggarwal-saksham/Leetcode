/*
 * Problem #2364: Count Number of Bad Pairs
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/9/2025, 11:52:27 AM
 * Link: https://leetcode.com/problems/count-number-of-bad-pairs/
 */

class Solution
{
    public:
        long long countBadPairs(vector<int> &nums)
        {
            long long n = nums.size();
            long long cnt = 0;
            unordered_map<int, int> mpp;
            for (int i = 0; i < n; i++)
            {
                cnt += mpp[nums[i] - i];
                mpp[nums[i] - i]++;
            }
            
            return (n *(n - 1) / 2) - cnt;
        }
};
