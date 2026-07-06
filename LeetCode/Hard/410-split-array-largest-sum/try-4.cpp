/*
 * Problem #410: Split Array Largest Sum
 * Difficulty: Hard
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/6/2026, 12:26:27 PM
 * Link: https://leetcode.com/problems/split-array-largest-sum/
 */

class Solution {
public:
    bool possible(vector<int>& nums, int k, int mid) {
        int sub = 1;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num > mid) {
                sub++;
                sum = num;
            } else {
                sum += num;
            }
        }

        return sub <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        long long l = *max_element(nums.begin(), nums.end());
        long long h = accumulate(nums.begin(), nums.end(), 0LL);

        while (l <= h) {
            long long mid = l + (h - l) / 2;

            if (possible(nums, k, mid))
                h = mid - 1;
            else
                l = mid + 1;
        }

        return (int)l;
    }
};
