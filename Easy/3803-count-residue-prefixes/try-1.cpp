/*
 * Problem #3803: Count Residue Prefixes
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/11/2026, 2:23:41 PM
 * Link: https://leetcode.com/problems/count-residue-prefixes/
 */

class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        set<int> st;
        st.insert(s[0]);
        int ans = 1;
        for (int i = 1; i < n; i++) {

            st.insert(s[i]);
            if (((i + 1) % 3) == st.size())
                ans++;
        }
        return ans;
    }
};
