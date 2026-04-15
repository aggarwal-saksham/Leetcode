/*
 * Problem #39: Combination Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/1/2025, 1:56:33 PM
 * Link: https://leetcode.com/problems/combination-sum/
 */

class Solution
{
    public:
        void backtrack(int idx, vector<int> &candidates, int target,
            vector<vector < int>> &ans, vector< int > &comb)
        {
            if (idx == candidates.size())
            {

                if (target == 0)
                {
                    ans.push_back(comb);
                }
                return;
            }

            if (target >= candidates[idx])
            {
                comb.push_back(candidates[idx]);
                backtrack(idx, candidates, target - candidates[idx], ans, comb);
                comb.pop_back();
            }
            backtrack(idx + 1, candidates, target, ans, comb);
        }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> comb;
        backtrack(0, candidates, target, ans, comb);
        return ans;
    }
};
