/*
 * Problem #503: Next Greater Element II
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/1/2026, 8:41:18 PM
 * Link: https://leetcode.com/problems/next-greater-element-ii/
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for(int i = 2 * n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i % n]){
                st.pop();
            }
            if(!st.empty() && st.top() > arr[i % n]){
                nge[i % n] = st.top();                
            }
                       
            st.push(arr[i % n]);
        }
        return nge;
        
    }
};
