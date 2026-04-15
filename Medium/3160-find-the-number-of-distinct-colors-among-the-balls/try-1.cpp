/*
 * Problem #3160: Find the Number of Distinct Colors Among the Balls
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/7/2025, 11:45:03 PM
 * Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/
 */

class Solution
{
    public:
        vector<int> queryResults(int limit, vector<vector<int>> &queries)
        {
            unordered_map<int, int> mpp1;
            unordered_map<int, int> mpp2;

            int n = queries.size();
            vector<int> ans;
            
            for (int i = 0; i < n; i++)
            {
                if (mpp1.find(queries[i][0]) != mpp1.end())
                {
                    if (mpp2[mpp1[queries[i][0]]] > 1)
                        mpp2[mpp1[queries[i][0]]]--;
                    else
                        mpp2.erase(mpp1[queries[i][0]]);
                }
                
                mpp1[queries[i][0]] = queries[i][1];
                mpp2[queries[i][1]]++;

                ans.push_back(mpp2.size());
            }
            return ans;
        }
};

