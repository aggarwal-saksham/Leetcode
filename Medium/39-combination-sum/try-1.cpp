/*
 * Problem #39: Combination Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/13/2024, 8:27:32 PM
 * Link: https://leetcode.com/problems/combination-sum/
 */

class Solution
{
    public:
        void findComb(int i, vector<int> &candidates, int target, vector<vector< int >> &ans, vector< int > &comb)
        {
            if (i == candidates.size())
            {
                if (target == 0)
                {
                    ans.push_back(comb);
                }
                return;
            }

            if (candidates[i] <= target)
            {
                comb.push_back(candidates[i]);
                findComb(i, candidates, target - candidates[i], ans, comb);
                comb.pop_back();
            }
            findComb(i + 1, candidates, target, ans, comb);
        }
    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> comb;
        findComb(0, candidates, target, ans, comb);
        return ans;
    }
};
