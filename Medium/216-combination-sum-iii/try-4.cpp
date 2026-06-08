/*
 * Problem #216: Combination Sum III
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 12:57:13 AM
 * Link: https://leetcode.com/problems/combination-sum-iii/
 */

class Solution {
public:
    void findComb(vector<vector<int>> &ans, vector<int> &comb, int k, int n){
        if(n < 0) return;
        if(comb.size() == k){
            if(n == 0) ans.push_back(comb);
            return;
        }
        if(comb.size() == 0){
            for(int i = 1; i <= 9; i++){
                comb.push_back(i);
                findComb(ans, comb, k, n-i);
                comb.pop_back();
            }
        }
        if(comb.size() > 0 && comb.size() < k){
            for(int i = comb.back() + 1; i <= 9; i++){
                comb.push_back(i);
                findComb(ans, comb, k, n-i);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)  {
        vector<vector<int>> ans;
        vector<int> comb;
        if(k > n) return ans;
        findComb(ans, comb, k, n);
        return ans;
    }
};
