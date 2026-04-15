/*
 * Problem #3443: Maximum Manhattan Distance After K Changes
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/20/2025, 5:21:39 PM
 * Link: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/
 */

class Solution
{
    public:
        int solve(char a, char b, string &s, int k)
        {
            int dist = 0, maxi = 0;

            for (char c: s)
            {
                if (c == a || c == b)
                {
                    dist++;
                }
                else
                {
                    if (k > 0)
                    {
                        k--;
                        dist++;
                    }
                    else
                    {
                        maxi = max(maxi, dist);
                        dist--;
                    }
                }
            }
            maxi = max(maxi, dist);

            return maxi;
        }
    int maxDistance(string s, int k)
    {
        if (k == s.size())
        {
            return k;
        }

        int nw = solve('N', 'W', s, k);
        int ne = solve('N', 'E', s, k);
        int sw = solve('S', 'W', s, k);
        int se = solve('S', 'E', s, k);

        return max({nw, ne, sw, se});
    }
};
