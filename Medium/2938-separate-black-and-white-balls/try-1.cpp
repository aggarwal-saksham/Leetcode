/*
 * Problem #2938: Separate Black and White Balls
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/16/2024, 12:22:19 AM
 * Link: https://leetcode.com/problems/separate-black-and-white-balls/
 */

class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int black = 0;
        for(char c : s){
            if(c == '0')
                swap += (long long)black;
            else
                black++;
        }
        return swap;
    }
};
