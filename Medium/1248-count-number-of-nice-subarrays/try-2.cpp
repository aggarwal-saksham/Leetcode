/*
 * Problem #1248: Count Number of Nice Subarrays
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 12/20/2025, 1:26:13 PM
 * Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
 */

class Solution {
public:
    // first solve lc 930 binary subarray
    int func(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int odds = 0;
        int l = 0, r = 0;

        while(r < n){
            if((nums[r] & 1) == 1) odds++;

            while(odds > k){
                if((nums[l] & 1) == 1) odds--; 
                l++;
            }

            cnt += r - l + 1;
            r++;
        }
        return cnt;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return {func(nums, k) - func(nums, k - 1)};
    }
};
