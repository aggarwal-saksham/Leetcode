/*
 * Problem #8: String to Integer (atoi)
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 3:48:52 PM
 * Link: https://leetcode.com/problems/string-to-integer-atoi/
 */

class Solution {
public:
    int myAtoi(string s) {
        bool first = false;
        long long num = 0;
        bool neg = false, signFound = false;
        for (char c : s) {
            if (isdigit(c)) {
                first = true;
                num *= 10;
                num += (c - '0');
                if (!neg && num > INT_MAX)
                    return INT_MAX;
                if (neg && -num < INT_MIN)
                    return INT_MIN;
            } 
            
            else if (!first && (c == '-' || c == '+') && !signFound) {
                signFound = true;
                neg = true ? (c == '-') : (c == '+');
            } 
            
            else if (!first && !signFound && c == ' ') {
                continue;
            } 
            
            else
                break;
        }
        if (num == 0)
            return 0;
        if (neg)
            num *= -1LL;

        return (int)num;
    }
};
