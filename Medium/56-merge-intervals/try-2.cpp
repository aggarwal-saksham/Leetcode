/*
 * Problem #56: Merge Intervals
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 10:07:34 PM
 * Link: https://leetcode.com/problems/merge-intervals/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(ans.empty()) {
                ans.push_back(intervals[i]);
                continue;
            }
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
            

        }
        return ans;
    }
};
