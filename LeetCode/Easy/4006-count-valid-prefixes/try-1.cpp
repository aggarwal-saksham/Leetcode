/*
 * Problem #4006: Count Valid Prefixes
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/1/2026, 8:07:07 PM
 * Link: https://leetcode.com/problems/count-valid-prefixes/
 */

class Solution {
public:
    int countValidPrefixes(string s) {
        int z = 0, v = 0;
        int cnt = 0;
        for(char c : s){
            if(c == '0') z++;
            else v++;
            if(abs(v - z) <= 1) cnt++;
        }
        return cnt;
    }
};
