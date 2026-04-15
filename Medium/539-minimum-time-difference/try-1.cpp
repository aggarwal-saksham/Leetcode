/*
 * Problem #539: Minimum Time Difference
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/16/2024, 2:52:43 PM
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
            for (int i = 0; i < n; i++)
            {
                int diff = abs(mins[(i - 1 + n) % n] - mins[i]);
                diff = min(diff, 1440 - diff);
                mindiff = min(diff, mindiff);
            }
            return mindiff;
        }
};
