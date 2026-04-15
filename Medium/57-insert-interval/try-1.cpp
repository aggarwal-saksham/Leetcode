/*
 * Problem #57: Insert Interval
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/2/2025, 1:59:57 PM
 * Link: https://leetcode.com/problems/insert-interval/
 */

class Solution
{
    public:
        vector<vector < int>> insert(vector<vector < int>> &intervals, vector< int > &newInterval)
        {
            vector<vector<int>> ans;
            int n = intervals.size();
            //if (n == 0) return ans.push_back(newInterval);
            int i = 0;
            while (i < n && intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
                i++;
            }

            while (i < n && intervals[i][0] <= newInterval[1])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                i++;
            }
            ans.push_back(newInterval);

            while (i < n)
            {
                ans.push_back(intervals[i]);
                i++;
            }
            return ans;
        }
};
