/*
 * Problem #2210: Count Hills and Valleys in an Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/27/2025, 3:13:16 PM
 * Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
 */

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int l = nums[0];
        int r = nums[2];
        int cnt = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            r = nums[i + 1];
            if(nums[i] > l && nums[i] > r){
                cnt++;
                l = nums[i];
            }
            else if(nums[i] < l && nums[i] < r){
                cnt++;
                l = nums[i];
            }

            else if(nums[i] == l){
                continue;
            }
        }
        return cnt;
    }
};
