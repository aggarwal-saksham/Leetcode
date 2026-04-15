/*
 * Problem #3442: Maximum Difference Between Even and Odd Frequency I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/10/2025, 2:54:50 PM
 * Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/
 */

class Solution
{
    public:
        int maxDifference(string s)
        {
            unordered_map<char, int> mpp;
            for (char c: s)
            {
                mpp[c]++;
            }
            int odd = INT_MIN, even = INT_MAX;
            for (auto it: mpp)
            {
                if (it.second &1 == 1)
                {
                    odd = max(odd, it.second);
                }
                else
                {
                    even = min(even, it.second);
                }
            }

            return odd - even;
        }
};
