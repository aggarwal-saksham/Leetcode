/*
 * Problem #645: Set Mismatch
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2025, 1:17:01 AM
 * Link: https://leetcode.com/problems/set-mismatch/
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long asum = 0, nsum = 0, asqsum = 0, nsqsum = 0;
        int n = nums.size();

        nsum = (1LL * n * (n + 1)) / 2;
        nsqsum = (1LL * n * (n + 1) * (2 * n + 1)) / 6;

        for (int num : nums) {
            asum += num;
            asqsum += 1LL * num * num;
        }

        long long eqn1 = asum - nsum;              // x - y
        long long eqn2 = (asqsum - nsqsum) / eqn1; // x + y

        long long rep = (eqn1 + eqn2) / 2;
        long long miss = rep - eqn1;

        return {(int)rep, (int)miss};
    }
};
