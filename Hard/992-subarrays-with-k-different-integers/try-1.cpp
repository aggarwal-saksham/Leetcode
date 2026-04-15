/*
 * Problem #992: Subarrays with K Different Integers
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2025, 1:01:56 AM
 * Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
 */

class Solution {
public:
    int func(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<int, int> freq;

        while (r < n) {
            freq[nums[r]]++;

            while (freq.size() > k) {
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                }
                l++;
            }

            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k - 1);
    }
};
