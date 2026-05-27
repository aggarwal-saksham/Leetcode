/*
 * Problem #3937: Minimum Operations to Make Array Modulo Alternating I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/23/2026, 8:26:58 PM
 * Link: https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         int n = nums.size();
        int ans = INT_MAX;

        for(int x = 0; x < k; x++) {
            for(int y = 0; y < k; y++) {

                if(x == y) continue;

                int ops = 0;

                for(int i = 0; i < n; i++) {

                    int target = (i % 2 == 0 ? x : y);
                    int rem = nums[i] % k;

                    int diff = abs(rem - target);

                    ops += min(diff, k - diff);
                }

                ans = min(ans, ops);
            }
        }

        return ans;
    }
};
