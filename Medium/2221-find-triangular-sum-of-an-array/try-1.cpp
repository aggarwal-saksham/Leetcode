/*
 * Problem #2221: Find Triangular Sum of an Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/30/2025, 7:55:48 PM
 * Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/
 */

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n--){
            for(int i = 0; i < n; i++){
                int temp = (nums[i] + nums[i + 1]) % 10;
                nums[i] = temp;
            }
        }
        return nums[0];
    }
};
