/*
 * Problem #45: Jump Game II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/1/2025, 12:57:30 AM
 * Link: https://leetcode.com/problems/jump-game-ii/
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int j = 0, i = 0;

        while (i < n - 1) {
            int reach = i + nums[i];
            if (reach >= n - 1) {
                j++;
                break;
            }

            int next = i;
            for (int k = i + 1; k <= reach; k++) {
                if (k + nums[k] > next + nums[next]) {
                    next = k;
                }
            }

            i = next;
            j++;
        }

        return j;
    }
};

