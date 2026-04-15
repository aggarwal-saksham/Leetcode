/*
 * Problem #389: Find the Difference
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/13/2024, 3:34:32 PM
 * Link: https://leetcode.com/problems/find-the-difference/
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0, sum2 = 0;
        for(char c : s){
            sum1 += c;
        }
        for(char c : t){
            sum2 += c;
        }
        int diff = sum2 - sum1;
        return (char)diff;
    }
};
