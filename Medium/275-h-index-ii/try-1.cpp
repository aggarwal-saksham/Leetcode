/*
 * Problem #275: H-Index II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/15/2025, 2:22:49 AM
 * Link: https://leetcode.com/problems/h-index-ii/
 */

class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1, ans = 0;
        while(l <= h){
            int m = l - ((l - h) / 2);
            if(nums[m] >= n - m){
                h = m - 1;
                ans = max(ans, n - m);
            }
            else{
                l = m + 1;
            }
        }
        return ans;
        
    }
};
