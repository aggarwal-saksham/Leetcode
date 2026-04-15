/*
 * Problem #3779: Minimum Number of Operations to Have Distinct Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/20/2025, 9:03:21 PM
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = n - 1; i >= 0; i--){
            if(st.find(nums[i]) != st.end()){
                return (i/3) + 1;
            }
            st.insert(nums[i]);
        }

        return 0;
    }
};
