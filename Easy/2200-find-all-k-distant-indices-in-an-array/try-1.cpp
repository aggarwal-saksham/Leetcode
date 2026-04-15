/*
 * Problem #2200: Find All K-Distant Indices in an Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 1:16:33 PM
 * Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
 */

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(nums[j] == key){
                    if(abs(i - j) <= k) ans.insert(i);
                }
            }
        }
        vector<int> res;
        for(auto it : ans){
            res.push_back(it);
        }
        return res;
    }
};
