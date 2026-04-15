/*
 * Problem #282: Expression Add Operators
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/28/2026, 12:35:16 AM
 * Link: https://leetcode.com/problems/expression-add-operators/
 */

class Solution {
public:
    void backtrack(vector<string> &ans, string exp, string &num, int target, int i, long currVal, long lastOperand){
        if(i == num.size()){
            if(currVal == target){
                ans.push_back(exp);
            }
            return;
        }

        for(int j = i; j < num.size(); j++){
            if(j > i && num[i] == '0') break;  

            string part = num.substr(i, j - i + 1);
            long val = stol(part);

            if(i == 0){
                backtrack(ans, part, num, target, j + 1, val, val);
            }
            else{
                backtrack(ans, exp + "+" + part, num, target, j + 1, currVal + val, val);
                backtrack(ans, exp + "-" + part, num, target, j + 1, currVal - val, -val);
                backtrack(ans, exp + "*" + part, num, target, j + 1, currVal - lastOperand + lastOperand * val, lastOperand * val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrack(ans, "", num, target, 0, 0, 0);
        return ans;
    }
};
