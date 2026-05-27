/*
 * Problem #3936: Minimum Swaps to Move Zeros to End
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/23/2026, 8:23:57 PM
 * Link: https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/
 */

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int z = 0;
        
        for(int n : nums){
            if(n == 0) z++;
        }

        int ans = 0;

        for(int i = 0; i < nums.size() - z; i++){
            if(nums[i] == 0) ans++;
        }

        return ans;
    }
};
