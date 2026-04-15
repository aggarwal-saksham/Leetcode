/*
 * Problem #3834: Merge Adjacent Equal Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/8/2026, 5:33:01 PM
 * Link: https://leetcode.com/problems/merge-adjacent-equal-elements/
 */

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        stack<long long> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long v = nums[i];
            if (st.empty() || st.top() != v) {
                st.push(v);
                continue;
            }
            while(!st.empty() && st.top() == v) {
                st.pop();
                v = (2LL * v);
            }
            st.push(v);
        }

        while (!st.empty()) {
            long long x = st.top();
            st.pop();
            
                ans.push_back(x);
           
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

