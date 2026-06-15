/*
 * Problem #3959: Check Good Integer
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2026, 12:52:46 PM
 * Link: https://leetcode.com/problems/check-good-integer/
 */

class Solution {
public:
    bool checkGoodInteger(int n) {
        int sq = 0;
        long long sum = 0;
        while(n > 0){
            int last = n % 10;
            n /= 10;
            sum += last;
            sq += last * 1LL * last;
            
        }
        return ((int)sq - sum) >= 50;
    }
};
