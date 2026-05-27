/*
 * Problem #1903: Largest Odd Number in String
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 12:02:20 AM
 * Link: https://leetcode.com/problems/largest-odd-number-in-string/
 */

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int i = n - 1;
        while(i >= 0){
            if((num[i] - '0') & 1){
                return num.substr(0, i + 1);
            }
            i--;
        }
        return  "";
    }
};
