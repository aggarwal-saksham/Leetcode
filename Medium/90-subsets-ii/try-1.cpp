/*
 * Problem #90: Subsets II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/14/2024, 9:04:34 PM
 * Link: https://leetcode.com/problems/subsets-ii/
 */

class Solution {
public:
    void helper(int i, vector<int>& arr, vector<int> subs,
                set<vector<int>>& ans) {
        //
        if (i == arr.size()) {
            sort(subs.begin(),subs.end());
            ans.insert(subs);
            return;
        }
        //
        vector<int> subsCopy = subs;
        subsCopy.push_back(arr[i]);
        helper(i + 1, arr, subsCopy, ans);
        helper(i + 1, arr, subs, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        set<vector<int>> ans;
        vector<int> subs;
        helper(0, arr, subs, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
