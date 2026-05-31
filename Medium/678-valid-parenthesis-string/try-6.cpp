/*
 * Problem #678: Valid Parenthesis String
 * Difficulty: Medium
 * Submission: Try 6
 * status: Accepted
 * Language: cpp
 * Date: 5/30/2026, 11:30:31 PM
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 */

class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;

        for(char c : s){
            if(c == '('){
                mini++;
                maxi++;
            }
            else if(c == ')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }
        return mini == 0;
    }
};
