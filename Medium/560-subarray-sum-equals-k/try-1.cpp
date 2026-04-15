/*
 * Problem #560: Subarray Sum Equals K
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2024, 11:50:52 PM
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 */

class Solution
{
    public:
        int subarraySum(vector<int> &nums, int k)
        {
            map<int,int> mpp;
            int sum = 0, cnt = 0;
            mpp[0] = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                int rem = sum - k;
                cnt += mpp[rem];
                mpp[sum] += 1;
            }
        return cnt;
        }
};
