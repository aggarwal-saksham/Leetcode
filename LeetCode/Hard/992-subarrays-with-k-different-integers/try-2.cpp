/*
 * Problem #992: Subarrays with K Different Integers
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/16/2026, 11:59:56 PM
 * Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
 */

class Solution {
public:
    int calcAtMost(vector<int>& nums, int k){
        int l = 0, r = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> freq;


        while(r < n){
            freq[nums[r]]++;
            while(freq.size() > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }
            if(freq.size() <= k){
                ans += (r - l + 1);
            }
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int n = nums.size();
       return calcAtMost(nums, k) - calcAtMost(nums, k - 1);
    }
};
