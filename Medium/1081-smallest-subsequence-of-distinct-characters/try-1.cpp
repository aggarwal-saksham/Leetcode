/*
 * Problem #1081: Smallest Subsequence of Distinct Characters
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/13/2025, 1:32:14 AM
 * Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 */

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        unordered_map<char, bool> inStack;
        stack<char> st;

        for (char c : s) {
            freq[c]--; 
            if (inStack[c]) continue; 
            while (!st.empty() && st.top() > c && freq[st.top()] > 0) {
                inStack[st.top()] = false;
                st.pop();
            }

            st.push(c);
            inStack[c] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
