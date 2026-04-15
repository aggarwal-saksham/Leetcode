/*
 * Problem #268: Missing Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/9/2024, 2:23:50 AM
 * Link: https://leetcode.com/problems/missing-number/
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int N = nums.size();
       int sum = (N*(N+1))/2;

       int s2 = 0;
       for(int i =0; i < N; i++){
        s2 += nums[i];
       }
       return (sum - s2);
    }
};
