/*
 * Problem #22: Generate Parentheses
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/15/2024, 2:28:08 PM
 * Link: https://leetcode.com/problems/generate-parentheses/
 */

class Solution {
public:
    void helper(vector<string> &ans, string &comb, int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(comb);
            return;
        }
        if(open > 0){
            comb.push_back('(');
            helper(ans, comb, open - 1, close);
            comb.pop_back();

        }
        if(close > open){
            comb.push_back(')');
            helper(ans, comb, open ,close - 1);
            comb.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        //vector<vector<string>> ans;
        vector<string> ans;
        string comb;
        helper(ans, comb, n, n);
        return ans;      
    }
};
