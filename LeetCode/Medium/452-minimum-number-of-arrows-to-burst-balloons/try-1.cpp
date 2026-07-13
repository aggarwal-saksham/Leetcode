/*
 * Problem #452: Minimum Number of Arrows to Burst Balloons
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2026, 1:00:26 AM
 * Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        int cnt = 1;

        int prev = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] <= prev) continue;
            cnt++;
            prev = points[i][1];
        }
        return cnt;
    }
};
