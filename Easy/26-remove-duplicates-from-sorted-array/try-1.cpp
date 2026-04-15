/*
 * Problem #26: Remove Duplicates from Sorted Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/6/2024, 11:34:05 PM
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                nums[i +1] = nums[j];
                i++;
            }

        }
        return i+1;

        
    }
};
