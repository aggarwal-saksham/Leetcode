/*
 * Problem #50: Pow(x, n)
 * Difficulty: Medium
 * Submission: Try 6
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2025, 4:17:51 PM
 * Link: https://leetcode.com/problems/powx-n/
 */

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;

        if(n == INT_MIN){
            x = 1/x;
            n = INT_MAX;
            ans *= x;
            /*coz intmin = -2^31
            int max = 2^31-1
            so mul one more time to make 2^31*/
        }

        if(n < 0){
            x = 1/x;
            n = -n;
        }
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
