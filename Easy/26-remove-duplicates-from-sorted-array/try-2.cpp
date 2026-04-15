/*
 * Problem #26: Remove Duplicates from Sorted Array
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 8:07:04 PM
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 1;
        while(r < nums.size()){
            if(nums[r] != nums[l]){
                l++;
                nums[l] = nums[r];
            }
            r++;
        }
        return l +1;
    }
};
