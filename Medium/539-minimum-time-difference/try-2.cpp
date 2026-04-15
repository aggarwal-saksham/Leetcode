/*
 * Problem #539: Minimum Time Difference
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/16/2024, 3:27:23 PM
 * Link: https://leetcode.com/problems/minimum-time-difference/
 */

class Solution
{
    public:
        int findMinDifference(vector<string> &timePoints)
        {
            vector<int> mins;
            for (int i = 0; i < timePoints.size(); i++)
            {
                int tp = (stoi(timePoints[i].substr(0, 2)) *60)
                                             +
                            (stoi(timePoints[i].substr(3, 2)));
                mins.push_back(tp);
            }
            sort(mins.begin(), mins.end());
            int n = mins.size();
            int mindiff = INT_MAX;
            int terminal_diff = 1440 - (mins.back() - mins[0]);
            for (int i = 1; i < n; i++)
            {
                int diff = abs(mins[i] - mins[i - 1]);
                diff = min(diff,terminal_diff);
                diff = min(diff, 1440 - diff);
                mindiff = min(diff, mindiff);
            }
            return mindiff;
        }
};
