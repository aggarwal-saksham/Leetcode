/*
 * Problem #1: Two Sum
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2024, 12:08:53 AM
 * Link: https://leetcode.com/problems/two-sum/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int rem = target - num;
            if (m.find(rem) != m.end())
            {
                return {m[rem], i};
            } 
            else
                m[nums[i]] = i;

        }
            return {-1, -1};
    }
};
