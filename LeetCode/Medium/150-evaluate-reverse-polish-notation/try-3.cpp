/*
 * Problem #150: Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 8/3/2026, 6:34:43 PM
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &s : tokens){
            if(s != "+" && s != "-" && s != "*" && s != "/"){
                st.push(stoi(s));
            }
            else{
                int d1 = st.top();
                st.pop();
                int d2 = st.top();
                st.pop();
                if(s == "+"){
                    st.push(d1 + d2);
                }
                if(s == "-"){
                    st.push(d2 - d1);
                }
                if(s == "*"){
                    st.push(d1 * d2);
                }
                if(s == "/"){
                    st.push(d2 / d1);
                }
            }
        }
        return st.top();
    }
};
