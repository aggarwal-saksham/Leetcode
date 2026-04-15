/*
 * Problem #2302: Count Subarrays With Score Less Than K
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2025, 12:51:00 AM
 * Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0, r = 0;
        long long cnt = 0;
        long long score = 0;
        long long sum = 0;
        while (r < n) {
            sum += nums[r];
            score = sum * (r - l  +1);

            while (score >= k) {
                sum -= nums[l];
                l++;
                score = sum * (r - l  +1);
                
            }

            cnt += r - l + 1;

            r++;
        }
        return cnt;
    }
};
