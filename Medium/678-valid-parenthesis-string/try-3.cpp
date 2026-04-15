/*
 * Problem #678: Valid Parenthesis String
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 1/8/2026, 4:33:10 PM
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 */

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftSt;
        stack<int> starSt;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') leftSt.push(i);
            else if(s[i] == '*') starSt.push(i);
            else{
                if(!leftSt.empty()) leftSt.pop();
                else if(!starSt.empty()) starSt.pop();
                else return false;
            }

        }
        while(!leftSt.empty()){
            if(starSt.empty()) return false;
            if(starSt.top() > leftSt.top()){
                starSt.pop();
                leftSt.pop();
            }
            else return false;
        }

        return (leftSt.empty());

        
    }
};
