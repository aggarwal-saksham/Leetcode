/*
 * Problem #2099: Find Subsequence of Length K With the Largest Sum
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2025, 2:09:13 PM
 * Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
 */

class Solution
{
    public:
        vector<int> maxSubsequence(vector<int> &nums, int k)
        {
            int n = nums.size();
            typedef pair<int, int> pii;
            priority_queue<pii, vector < pii>, greater < pii>> minH;

            for (int i = 0; i < n; i++)
            {
                minH.push({ nums[i],
                    i });

                if (minH.size() > k)
                    minH.pop();
            }

            vector<int> ans;

            while (!minH.empty())
            {
                ans.push_back(minH.top().second);
                minH.pop();
            }

            sort(ans.begin(), ans.end());

            for (int i = 0; i < ans.size(); i++)
            {
                ans[i] = nums[ans[i]];
            }

            return ans;
        }
};
