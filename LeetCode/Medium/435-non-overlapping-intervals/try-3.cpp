/*
 * Problem #435: Non-overlapping Intervals
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 8/8/2026, 12:46:04 PM
 * Link: https://leetcode.com/problems/non-overlapping-intervals/
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        int n = intervals.size();
        int prev = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < prev){
                cnt++;
                prev = min(prev, intervals[i][1]);
            }
            else prev = intervals[i][1];
        }
        return cnt;
    }
};
