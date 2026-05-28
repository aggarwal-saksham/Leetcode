/*
 * Problem #50: Pow(x, n)
 * Difficulty: Medium
 * Submission: Try 7
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 3:39:41 PM
 * Link: https://leetcode.com/problems/powx-n/
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n == INT_MIN){
            n = INT_MAX;
            x = 1/x;
            ans *= x;
        }
        if(n < 0){
            x = 1/x;
            n = -n;
        }
        while(n){
            if((n&1) == 1){
                ans *= x;
                n--;
            }
            else{
                x *= x;
                n /= 2;
            }
        }
        return ans;
    }
};
