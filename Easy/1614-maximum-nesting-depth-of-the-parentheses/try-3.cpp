/*
 * Problem #1614: Maximum Nesting Depth of the Parentheses
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 1:26:27 AM
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 */

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int cnt = 0;
       
        for(char c : s){
            
            if(c == '(' && st.size() == cnt){
                st.push(c);
                cnt++;
            }
            else if(c == '(' && st.size() < cnt){
                st.push(c);
            }
            if(c == ')'){
                st.pop();
            }

        }
    return cnt;
        //(()())
//empty and  ( cnt++ & push
//top ( and curr ( & st.size == cnt  push & cnt++ 
//top ( and curr ( & st.size < cnt push  
//top ( and curr ) st.pop 
//
    }
};
