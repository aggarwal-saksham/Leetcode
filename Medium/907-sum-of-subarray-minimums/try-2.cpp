/*
 * Problem #907: Sum of Subarray Minimums
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2026, 1:21:42 AM
 * Link: https://leetcode.com/problems/sum-of-subarray-minimums/
 */

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        

        int n = arr.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i= 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }

        long long ans = 0;
        long long mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            ans = (ans + (1LL * arr[i] * (i - pse[i]) % mod) * (nse[i] - i) % mod) % mod; 
        
        }
        return (int)ans;
    }
};
