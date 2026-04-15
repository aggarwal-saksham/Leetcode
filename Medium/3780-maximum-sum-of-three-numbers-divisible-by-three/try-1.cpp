/*
 * Problem #3780: Maximum Sum of Three Numbers Divisible by Three
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/20/2025, 9:26:49 PM
 * Link: https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/
 */

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> zero, one, two;

        for (int num : nums) {
            if (num % 3 == 0) zero.push_back(num);
            else if (num % 3 == 1) one.push_back(num);
            else two.push_back(num);
        }

        sort(zero.rbegin(), zero.rend());
        sort(one.rbegin(), one.rend());
        sort(two.rbegin(), two.rend());

        long long ans = 0;

        if (zero.size() >= 3) {
            ans = max(ans, (long long)zero[0] + zero[1] + zero[2]);
        }

        if (one.size() >= 3) {
            ans = max(ans, (long long)one[0] + one[1] + one[2]);
        }

        if (two.size() >= 3) {
            ans = max(ans, (long long)two[0] + two[1] + two[2]);
        }

        if (!zero.empty() && !one.empty() && !two.empty()) {
            ans = max(ans, (long long)zero[0] + one[0] + two[0]);
        }

        return (int)ans;
    
    }
};
