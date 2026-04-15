/*
 * Problem #50: Pow(x, n)
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2025, 5:13:14 PM
 * Link: https://leetcode.com/problems/powx-n/
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        
        if(n == INT_MIN){
            x = 1/x;
            n = INT_MAX;
            ans = ans * x;

        }

        if(n < 0){
            x = 1/x;
            n = -n;
        }
        while(n > 0){
            //for odd
            if((n & 1) == 1){
                ans *= x;
                n--;
            }
            else{
                x = x * x;
                n = n / 2;
            }
        }
        return ans;
        
    }
};
