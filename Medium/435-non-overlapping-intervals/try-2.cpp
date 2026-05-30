/*
 * Problem #435: Non-overlapping Intervals
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/30/2026, 8:15:03 PM
 * Link: https://leetcode.com/problems/non-overlapping-intervals/
 */

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                cnt++;
                prev = i;
            }
        }
        return n - cnt;        
    }
};
