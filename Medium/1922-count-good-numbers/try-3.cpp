/*
 * Problem #1922: Count Good Numbers
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/6/2026, 5:58:01 PM
 * Link: https://leetcode.com/problems/count-good-numbers/
 */

class Solution {
public:
    int M = 1e9 + 7;
    long long findpow(long long x, long long n) {
        long long ans = 1;

        while(n){
            if((n&1) == 1){
                ans = (ans * x) % M;
                n--;
            }
            else{
                x = (x * x) % M;
                n /= 2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        return (long long)findpow(5, (n + 1) / 2) * findpow(4, n / 2) % M;
    }
};
