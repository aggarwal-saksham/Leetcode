/*
 * Problem #1423: Maximum Points You Can Obtain from Cards
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/5/2026, 7:01:23 PM
 * Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 */

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        int curr = 0;
        while(l < k){
            curr += nums[l];
            l++;
            
        }
        l--;
        int ans = 0;
        while(l >= 0){
            ans = max(ans, curr);
            curr -= nums[l];
            curr += nums[r];
            l--;r--;
        }
        ans = max(ans, curr);
        return ans;

    }
};
