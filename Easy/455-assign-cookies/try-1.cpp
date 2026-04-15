/*
 * Problem #455: Assign Cookies
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/31/2024, 3:32:29 PM
 * Link: https://leetcode.com/problems/assign-cookies/
 */

class Solution
{
    public:
        int findContentChildren(vector<int> &g, vector<int> &s)
        {

            sort(s.begin(), s.end());
            sort(g.begin(), g.end());
           	//int cnt = 0;
            int n1 = g.size();
            int n2 = s.size();
            int l = 0;
            int r = 0;
            while(l < n1 && r < n2)
            {
                if (s[r] >= g[l])
                {
                    l++;
                    r++;
                }
                else r++;
            }
            return l;
        }
};
