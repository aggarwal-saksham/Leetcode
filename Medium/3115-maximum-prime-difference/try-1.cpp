/*
 * Problem #3115: Maximum Prime Difference
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/24/2026, 12:36:10 AM
 * Link: https://leetcode.com/problems/maximum-prime-difference/
 */

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size(), l, r;
        for ( l = 0 ;l < n; l++) {
            if (isPrime(nums[l]))
                break;
        }
        for ( r = n - 1; r >= 0; r--) {
            if (isPrime(nums[r]))
                break;
        }

        return r - l;
    }
};
