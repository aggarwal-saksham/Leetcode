/*
 * Problem #3452: Sum of Good Numbers
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/15/2025, 8:11:19 PM
 * Link: https://leetcode.com/problems/sum-of-good-numbers/
 */

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                if (nums[i + k] < nums[i])
                    sum += nums[i];
            } 
            else if (i >= k && i < nums.size() - k) {
                if (nums[i + k] < nums[i] && nums[i - k] < nums[i])
                    sum += nums[i];
            } 
            else {
                if (nums[i - k] < nums[i])
                    sum += nums[i];
            }
        }
        return sum;
    }
};
