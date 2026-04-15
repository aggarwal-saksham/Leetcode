/*
 * Problem #455: Assign Cookies
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2025, 5:10:02 PM
 * Link: https://leetcode.com/problems/assign-cookies/
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        int l = 0, r = 0;
        while(l < g.size() && r < s.size()){
            if(g[l] <= s[r]){
                ans++;
                l++;
                r++;
            }

            else{
                r++;
            }
        }
        return ans;
    }
};
