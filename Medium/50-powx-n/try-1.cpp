/*
 * Problem #50: Pow(x, n)
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/1/2024, 11:12:50 PM
 * Link: https://leetcode.com/problems/powx-n/
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n == 0) return 1;
        if(x == 0) return 0;
        if(x == 1) return 1;
        if(x == -1 && n > 0 && ((n & 1) == 1)) 
        return -1;
        if(x == -1 && n > 0 && ((n & 1) == 0)) 
        return 1;
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
