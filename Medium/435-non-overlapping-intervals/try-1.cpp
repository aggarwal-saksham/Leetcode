/*
 * Problem #435: Non-overlapping Intervals
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2025, 3:27:38 PM
 * Link: https://leetcode.com/problems/non-overlapping-intervals/
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        int n = intervals.size();
        vector<int> prev = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < prev[1]) {
                if(intervals[i][1] < prev[1]){
                    prev = intervals[i];
                }
                cnt++;
            }
            else{
                prev = intervals[i];
            }
        }
        return cnt;
    }
};
