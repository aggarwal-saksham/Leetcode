/*
 * Problem #2410: Maximum Matching of Players With Trainers
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2025, 12:05:15 PM
 * Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
 */

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
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
