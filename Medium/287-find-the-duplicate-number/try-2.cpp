/*
 * Problem #287: Find the Duplicate Number
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 8:40:11 PM
 * Link: https://leetcode.com/problems/find-the-duplicate-number/
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // use slow fast ptr like totoise hare in linkedlists
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];
        /* iterate once before entering loop so
         that nums[0] == nums[0] dont happen */
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
