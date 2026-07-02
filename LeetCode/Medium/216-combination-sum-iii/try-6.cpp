/*
 * Problem #216: Combination Sum III
 * Difficulty: Medium
 * Submission: Try 6
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 5:55:07 PM
 * Link: https://leetcode.com/problems/combination-sum-iii/
 */

class Solution {
public:
    void backtrack (int k, vector<int>& curr, int i, int n, vector<vector<int>>& ans){
        if(i == k){
            if(n == 0) ans.push_back(curr);
            return;
        }
        if(curr.size() == 0){
            for(int j = 1; j <= 9; j++){
                curr.push_back(j);
                backtrack(k, curr, i + 1, n - j, ans);
                curr.pop_back();
            }
        }
        else{
            for(int j = curr.back() + 1; j <= 9; j++){
                curr.push_back(j);
                backtrack(k, curr, i + 1, n - j, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> ans;
        vector<int> curr;

        backtrack(k, curr, 0, n, ans);

        return ans;
    }
};
