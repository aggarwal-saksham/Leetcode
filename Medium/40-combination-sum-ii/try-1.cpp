/*
 * Problem #40: Combination Sum II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/14/2024, 8:05:21 PM
 * Link: https://leetcode.com/problems/combination-sum-ii/
 */

class Solution {
public:
    void findComb(int i, vector<int>& candidates, int target,
                  vector<vector<int>>& ans, vector<int>& comb) {

        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        // int j;
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;
            comb.push_back(candidates[j]);
            findComb(j + 1, candidates, target - candidates[j], ans, comb);
            comb.pop_back();
        }

        // findComb(i + 1, candidates, target, ans, comb);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        findComb(0, candidates, target, ans, comb);
        return ans;
    }
};
