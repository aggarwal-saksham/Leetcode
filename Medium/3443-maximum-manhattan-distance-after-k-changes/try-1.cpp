/*
 * Problem #3443: Maximum Manhattan Distance After K Changes
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/20/2025, 2:30:27 PM
 * Link: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/
 */

class Solution {
public:
    int maxDistance(string st, int k) {
        
        int n = 0, s = 0, e = 0, w = 0;
        int ans = 0;
        for(char c : st){
            if(c == 'N') n++;
            if(c == 'S') s++;
            if(c == 'W') w++;
            if(c == 'E') e++;

            int d = abs(n-s) + abs(e-w);
            int opp = min(n, s) + min(e, w);

            int flips = min(k, opp);
            int newd = d + flips * 2;
            ans = max(ans, newd);

           
        }
        return ans;
    }
};
