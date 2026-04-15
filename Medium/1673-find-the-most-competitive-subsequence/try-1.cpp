/*
 * Problem #1673: Find the Most Competitive Subsequence
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2025, 7:39:35 PM
 * Link: https://leetcode.com/problems/find-the-most-competitive-subsequence/
 */

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        k = n -k;
        stack<int> st;
        for (int num : nums) {
            while (!st.empty() && k > 0 && st.top() > num) {
                st.pop();
                k--;
            }

            st.push(num);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

               
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
