/*
 * Problem #3783: Mirror Distance of an Integer
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/21/2025, 6:18:17 PM
 * Link: https://leetcode.com/problems/mirror-distance-of-an-integer/
 */

class Solution {
public:
    int mirrorDistance(int n) {
        int copy = n, rem;
        int rev = 0;
        while(copy){
            rem = copy % 10;
            rev = rev * 10 + rem;
            copy /= 10;
            
            
        }
        cout << rev;
        return abs(n - rev);
    }
};
