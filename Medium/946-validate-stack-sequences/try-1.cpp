/*
 * Problem #946: Validate Stack Sequences
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/28/2025, 9:02:17 PM
 * Link: https://leetcode.com/problems/validate-stack-sequences/
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int l = 0, r = 0;
        while(l < n && r < n){
            while(l < n && pushed[l] != popped[r]){
                st.push(pushed[l]);
                l++;
            }
            r++;
            while(!st.empty() && r < n && st.top() == popped[r]){
                st.pop();
                r++;
            }
            l++;
        }

        return (st.empty()) ? true : false;

    }
};
