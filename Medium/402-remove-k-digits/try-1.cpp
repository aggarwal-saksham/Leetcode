/*
 * Problem #402: Remove K Digits
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/28/2025, 5:39:06 PM
 * Link: https://leetcode.com/problems/remove-k-digits/
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k)   
            return "0";
        stack<char> st;
        for(char c : num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }

            st.push(c);
        }
        while(k > 0){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        int i = ans.length() - 1;
        while(i >= 0 && ans[i] == '0'){
            if(ans[i] != '0') break;
            ans.pop_back();
            i--;
        }
        reverse(ans.begin(), ans.end());
        if(ans == "") ans += '0';
        return ans;
    }
};
