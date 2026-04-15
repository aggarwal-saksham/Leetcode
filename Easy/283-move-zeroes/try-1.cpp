/*
 * Problem #283: Move Zeroes
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/7/2024, 5:35:39 PM
 * Link: https://leetcode.com/problems/move-zeroes/
 */

class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) {
            return nums;
        }

        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[j], nums[i]);
                j++;
            }
        }

        return nums; // Moved return statement outside the loop and if statement
    }
};
