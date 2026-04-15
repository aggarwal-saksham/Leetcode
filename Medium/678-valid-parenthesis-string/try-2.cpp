/*
 * Problem #678: Valid Parenthesis String
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2025, 12:23:56 AM
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 */

class Solution {
public:
    bool checkValidString(string s) {
        int a = 0, b = 0;
        for(char c : s){
            if(c == '('){
                a++;
                b++;
            }
            else if(c == ')'){
                a--;
                b--;
            }

            else{
                a--;
                b++;
            }
            if(a < 0) a = 0;
            if(b < 0) return false;
        }
        return (!a);
    }
};
