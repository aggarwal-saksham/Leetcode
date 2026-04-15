/*
 * Problem #7: Reverse Integer
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2024, 3:07:20 PM
 * Link: https://leetcode.com/problems/reverse-integer/
 */

class Solution {
public:
    int reverse(int x) {
        int last_digit;
        long rev_num = 0;
        while(x){
            last_digit = x % 10;
            x = x / 10;
            rev_num = (rev_num * 10) + last_digit;
        }
        if(rev_num>INT_MAX || rev_num<INT_MIN) return 0;
        return (int)rev_num;
        
        
    }
};
