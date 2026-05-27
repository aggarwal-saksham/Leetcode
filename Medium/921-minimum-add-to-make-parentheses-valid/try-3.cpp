/*
 * Problem #921: Minimum Add to Make Parentheses Valid
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 8:32:23 PM
 * Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, neg = 0;
        for(char c : s){
            if(c == '('){
                cnt++;
            }
            else{
                cnt--;
                if(cnt < 0){
                    cnt = 0;
                    neg++;
                }
            }
        }
        return cnt + neg;
        //(((())()((())
    }
};
