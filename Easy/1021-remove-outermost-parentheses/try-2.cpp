/*
 * Problem #1021: Remove Outermost Parentheses
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/26/2026, 11:45:24 PM
 * Link: https://leetcode.com/problems/remove-outermost-parentheses/
 */

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        //()()
        int start = 0;
        for(char c : s){
                if(start >= 1) ans += c;
            if(c == '('){
                start++;
            }
            else{
                if(start == 1){
                    ans.pop_back();
                }
                start--;
            }
        }
        return ans;
    }
};
