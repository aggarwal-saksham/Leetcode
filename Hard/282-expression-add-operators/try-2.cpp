/*
 * Problem #282: Expression Add Operators
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/9/2026, 4:40:33 PM
 * Link: https://leetcode.com/problems/expression-add-operators/
 */

class Solution {
public:
    void backtrack(vector<string>& ans, string exp, string& num, int target,
                   int i, long currVal, long lastOperand) {
        if (i == num.size()) {
            if (currVal == target) {
                ans.push_back(exp);
            }
            return;
        }

        

        for (int j = 1; j <= num.size() - i; j++) {
            if(j > 1 && num[i] == '0') break;

            string sub = num.substr(i, j);
            long val = stol(sub);

            if(i == 0){
                backtrack(ans, sub, num, target, i + j, val, val);
            }

            else{
                backtrack(ans, exp + "+" + sub, num, target, i + j, currVal + val, val);
                backtrack(ans, exp + "-" + sub, num, target, i + j, currVal - val, -val);
                backtrack(ans, exp + "*" + sub, num, target, i + j, currVal - lastOperand + (lastOperand * val), lastOperand * val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrack(ans, "", num, target, 0, 0, 0);
        return ans;
    }
};
