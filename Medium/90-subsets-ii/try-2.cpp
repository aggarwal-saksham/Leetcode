/*
 * Problem #90: Subsets II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 12/14/2024, 11:46:43 PM
 * Link: https://leetcode.com/problems/subsets-ii/
 */

class Solution {
public:
    void helper(int i, vector<int>& arr, vector<int> subs,
                vector<vector<int>>& ans) {
        //
        
            ans.push_back(subs);
        
        for(int j = i; j < arr.size(); j++){
            if(j != i && arr[j] == arr[j-1]) continue;

            //
            //vector<int> subsCopy = subs;
            subs.push_back(arr[j]);
            helper(j + 1, arr, subs, ans);
            subs.pop_back();
           // helper(j + 1, arr, subs, ans);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> subs;
        sort(arr.begin(), arr.end());
        helper(0, arr, subs, ans);
        return ans;
    }
};
