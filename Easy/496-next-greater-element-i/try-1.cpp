/*
 * Problem #496: Next Greater Element I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/3/2024, 9:57:12 PM
 * Link: https://leetcode.com/problems/next-greater-element-i/
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> nge;
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = n2 - 1; i >= 0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge[nums2[i]] = -1;
            }
            else{
                nge[nums2[i]] = st.top();
            }
            
            st.push(nums2[i]);
            
        }
        for(int i = 0; i < n1; i++){
            ans.push_back(nge[nums1[i]]);
        }
        return ans;
    }
};
