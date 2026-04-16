/*
 * Problem #8: String to Integer (atoi)
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 4/16/2026, 7:06:42 PM
 * Link: https://leetcode.com/problems/string-to-integer-atoi/
 */

class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        bool isNeg = false;
        bool digFound = false;
        bool signFound = false;
        for(char c : s){
            if(c == ' ' && !digFound && !signFound){
                continue;                
            }

            if((c == '+' || c == '-') && !digFound && !signFound){
                signFound = true;
                isNeg = (c == '-');
                continue;
            }

            if(c >= '0' && c <= '9'){
                digFound = true;
                num = num * 10 + (c - '0');
                if (!isNeg && num > INT_MAX) return INT_MAX;
                if (isNeg && -num < INT_MIN) return INT_MIN;
                continue;
            }

            if(!isdigit(c)){
                break;
            }
        }
        if(isNeg) num *= -1LL;
        
        return (int)num;
    }
};
