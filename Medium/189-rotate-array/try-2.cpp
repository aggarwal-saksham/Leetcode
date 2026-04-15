/*
 * Problem #189: Rotate Array
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/15/2024, 3:03:41 PM
 * Link: https://leetcode.com/problems/rotate-array/
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return; 

        int temp[k];
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
            /*
            [1234567]
            [567]
            */
        }
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
             /*
            [1231234]
            [567]
            */
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
             /*
            [56712344]
            [567]
            */
        }
    }
};
