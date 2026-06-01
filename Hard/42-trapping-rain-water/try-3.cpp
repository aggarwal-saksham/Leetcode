/*
 * Problem #42: Trapping Rain Water
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/1/2026, 11:52:53 PM
 * Link: https://leetcode.com/problems/trapping-rain-water/
 */

class Solution
{
    public:
        int trap(vector<int> &nums)
        {
            int n = nums.size();
            int l = 0, r = n - 1;
            int lMax = 0, rMax = 0, total = 0;            

            while(l < r){
                if(nums[l] <= nums[r]){
                    if(nums[l] < lMax){
                        total += lMax - nums[l];
                    }
                    else lMax = nums[l];
                    l++;
                }
                else{
                    if(nums[r] < rMax){
                        total += rMax - nums[r];
                    }
                    else rMax = nums[r];
                    r--;
                }
            }
             

            return total;
        }
};
