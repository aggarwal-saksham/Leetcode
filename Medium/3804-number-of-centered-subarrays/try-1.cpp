/*
 * Problem #3804: Number of Centered Subarrays
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/11/2026, 2:32:00 PM
 * Link: https://leetcode.com/problems/number-of-centered-subarrays/
 */

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> st;
            long long total = 0;
            for(int j = i; j < n; j++){
                st.insert(nums[j]);
                total += (long long) nums[j];
                if(st.find(total) != st.end()) ans++;
            }
            
        }
        return ans;
    }
};
