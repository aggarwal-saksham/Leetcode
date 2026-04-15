/*
 * Problem #921: Minimum Add to Make Parentheses Valid
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 10/9/2024, 5:57:32 PM
 * Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 */

class Solution {
public:
//((())
//)))()
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.length();
        for(char c : s){
            if(!st.empty() && c == ')' && st.top() =='('){
                st.pop();
            }
            else{
                st.push(c);
            }

        }
        return st.size();
        
    }
};
