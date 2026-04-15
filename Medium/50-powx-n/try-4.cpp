/*
 * Problem #50: Pow(x, n)
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2025, 4:14:39 PM
 * Link: https://leetcode.com/problems/powx-n/
 */

class Solution {
public:
    double myPow(double x, int n) {

        if(n == INT_MIN){
            x = 1/x;
            n = INT_MAX - 1;
        }

        if(n < 0){
            x = 1/x;
            n = -n;
        }
        double ans = 1;
        while(n){
            if((n & 1) == 1){
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
