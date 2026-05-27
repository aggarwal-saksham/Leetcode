/*
 * Problem #45: Jump Game II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/23/2026, 5:02:12 PM
 * Link: https://leetcode.com/problems/jump-game-ii/
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int jumps = 0, i = 0;

        while (i < n - 1) {
            int reach = i + nums[i];
            if (reach >= n - 1) {
                jumps++;
                break;
            }

            int next = i;
            for (int k = i + 1; k <= reach; k++) {
                if (k + nums[k] > next + nums[next]) {
                    next = k;
                }
            }

            i = next;
            jumps++;
        }

        return jumps;
    }
};

