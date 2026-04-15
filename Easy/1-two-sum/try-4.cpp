/*
 * Problem #1: Two Sum
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 8/28/2024, 7:07:04 PM
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
            //if rem evalue is found in map
            {
                return {m[rem], i};
            } 
            else
                m[nums[i]] = i;
            //if rem not found,then store current el and iteratek

        }
            return {-1, -1};
    }
};
