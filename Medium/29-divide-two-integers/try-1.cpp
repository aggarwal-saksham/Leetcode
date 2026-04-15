/*
 * Problem #29: Divide Two Integers
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/30/2024, 11:05:54 PM
 * Link: https://leetcode.com/problems/divide-two-integers/
 */

class Solution {
public:
    bool sign_check(int dividend, int divisor){
        if(dividend > 0 && divisor < 0) return false;
        if(dividend < 0 && divisor > 0) return false;
        return true;

    }
    int divide(int dividend, int divisor) {
        bool sign = sign_check(dividend, divisor);
        if(dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;

         long long n = abs((long long)dividend);  
        long long d = abs((long long)divisor);
        int ans = 0;
        while(n >= d){

            int cnt = 0;
            while(n >= (d << (cnt + 1))){
                cnt++;
            }
            ans += 1 << cnt;
            n = n - (d << cnt);



        }
        if (sign == true && ans > INT_MAX) 
        return INT_MAX;
        if(sign == false && ans > INT_MAX)
        return INT_MIN;

        return (sign ? ans : (-1 * ans));
    }
};
