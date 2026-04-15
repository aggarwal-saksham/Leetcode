/*
 * Problem #56: Merge Intervals
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/3/2025, 1:58:17 AM
 * Link: https://leetcode.com/problems/merge-intervals/
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 1;
        while(i < n){
            if(intervals[i][0] <= intervals[i - 1][1]){
                int mini = intervals[i - 1][0];
                int maxi = intervals[i - 1][1];
                while(i < n && intervals[i][0] <= maxi){
                    mini = min(mini, intervals[i - 1][0]);
                    maxi = max(maxi, intervals[i][1]);
                    i++;
                    //continue;
                }
                ans.push_back({mini, maxi});
                i++;
                //continue;
            }
            else {
                ans.push_back(intervals[i - 1]);
                i++;
            }

        }
            if (ans.empty() || ans.back()[1] < intervals[n - 1][0]) {
                ans.push_back(intervals[n - 1]);
            }

        return ans;
    }
};
