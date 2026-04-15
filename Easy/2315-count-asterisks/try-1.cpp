/*
 * Problem #2315: Count Asterisks
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/13/2026, 3:00:00 PM
 * Link: https://leetcode.com/problems/count-asterisks/
 */

class Solution {
public:
    int countAsterisks(string s) {
        int pipes = 0;
        int stars = 0;
        for(char c : s){
            if(c == '|') pipes++;
            if(c == '*'){
                if(pipes % 2 == 0) stars++;
            }
        }
        return stars;
    }
};
