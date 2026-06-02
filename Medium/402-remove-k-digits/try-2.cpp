/*
 * Problem #402: Remove K Digits
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2026, 2:36:17 PM
 * Link: https://leetcode.com/problems/remove-k-digits/
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c : num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }

            st.push(c);
        }

        string ans = "";
        while(!st.empty() && k){
            st.pop();k--;
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int l = 0;
        while(l < ans.length() && ans[l] == '0'){
            l++;
        }

        return (l == ans.length()) ? "0" : ans.substr(l);
    }
};
