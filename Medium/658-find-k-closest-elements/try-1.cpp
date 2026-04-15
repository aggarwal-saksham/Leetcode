/*
 * Problem #658: Find K Closest Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/23/2025, 12:04:05 AM
 * Link: https://leetcode.com/problems/find-k-closest-elements/
 */

class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            priority_queue<pair<int, int>> maxH;
            for (int i = 0; i < arr.size(); i++)
            {
                maxH.push({ abs(arr[i] - x), i });
                if (maxH.size() > k)
                {
                    maxH.pop();
                }
            }

            vector<int> ans;
            while (!maxH.empty())
            {
                int ind = maxH.top().second;
                ans.push_back(arr[ind]);
                maxH.pop();
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
};
