/*
 * Problem #347: Top K Frequent Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/23/2025, 1:59:19 PM
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 */

class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> mpp;
            int n = nums.size();
            for (int num: nums)
            {
                mpp[num]++;
            }

            typedef pair<int, int> pii;
            priority_queue<pii, vector <pii>, greater <pii>> minH;

            for(auto i : mpp)
            {
                minH.push({i.second, i.first});
                if(minH.size() > k)
                {
                    minH.pop();
                }
                
            }

            vector<int> ans;

            while(!minH.empty())
            {
                ans.push_back(minH.top().second);
                minH.pop();
            }

            return ans;

        }
};
