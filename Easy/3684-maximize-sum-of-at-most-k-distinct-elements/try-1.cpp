/*
 * Problem #3684: Maximize Sum of At Most K Distinct Elements
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/14/2025, 4:42:57 PM
 * Link: https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/
 */

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        set<int> st;
        int i = 0;
        vector<int> ans;
        while(i < nums.size() && k){
            if(st.find(nums[i]) == st.end()){
                ans.push_back(nums[i]);
                st.insert(nums[i]);
                k--;
            }
            i++;
        }
        return ans;
        
    }
};
