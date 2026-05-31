/*
 * Problem #56: Merge Intervals
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/30/2026, 8:27:28 PM
 * Link: https://leetcode.com/problems/merge-intervals/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
            

        }
        return ans;
    }
};
