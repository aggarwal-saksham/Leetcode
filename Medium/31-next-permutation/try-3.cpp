/*
 * Problem #31: Next Permutation
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 7:40:56 PM
 * Link: https://leetcode.com/problems/next-permutation/
 */

class Solution {
public:
// 1 2 3 5 4
// 1 2 4 3 5

// 4 1 2 5 3

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                ind = i - 1;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i > ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
    }
};
