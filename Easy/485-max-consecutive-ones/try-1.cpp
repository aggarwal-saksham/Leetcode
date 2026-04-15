/*
 * Problem #485: Max Consecutive Ones
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/9/2024, 1:24:36 AM
 * Link: https://leetcode.com/problems/max-consecutive-ones/
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum = 0; 
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if(nums[i] == 1){
                count++;
                maximum = max(maximum,count);
            }
            else{
                count = 0;
            }
        } 
        return maximum;
    }
};
