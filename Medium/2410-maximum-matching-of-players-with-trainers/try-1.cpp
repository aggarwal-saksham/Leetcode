/*
 * Problem #2410: Maximum Matching of Players With Trainers
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2025, 5:15:26 PM
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
