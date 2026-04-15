/*
 * Problem #946: Validate Stack Sequences
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/28/2025, 10:45:13 PM
 * Link: https://leetcode.com/problems/validate-stack-sequences/
 */

class Solution {
public:
    bool dfs(int i, vector<int>& pushed, vector<int>& popped, vector<int>& st, int j) {
        if (j == popped.size()) return true; 
        if (i < pushed.size()) {
            // Try pushing
            st.push_back(pushed[i]);
            if (dfs(i + 1, pushed, popped, st, j)) return true;
            st.pop_back();
        }
        // Try popping
        if (!st.empty() && st.back() == popped[j]) {
            int top = st.back(); st.pop_back();
            if (dfs(i, pushed, popped, st, j + 1)) return true;
            st.push_back(top); // backtrack
        }
        return false;
    }

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        return dfs(0, pushed, popped, st, 0);
    }
};

