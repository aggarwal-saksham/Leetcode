/*
 * Problem #3683: Earliest Time to Finish One Task
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/14/2025, 4:36:31 PM
 * Link: https://leetcode.com/problems/earliest-time-to-finish-one-task/
 */

class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for(int i = 0; i < tasks.size(); i++){
            ans = min(ans, tasks[i][0] + tasks[i][1]);
        }
        return ans;
    }
};
