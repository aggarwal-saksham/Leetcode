/*
 * Problem #2375: Construct Smallest Number From DI String
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/18/2025, 6:52:34 PM
 * Link: https://leetcode.com/problems/construct-smallest-number-from-di-string/
 */

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";

        stack<int> st;
        for (int i = 0; i <= pattern.length(); i++) {
            st.push(i + 1);
            if (i == pattern.length() || pattern[i] == 'I') {
                while (!st.empty()) {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }

        return ans;
    }
};
