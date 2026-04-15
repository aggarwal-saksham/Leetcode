/*
 * Problem #3712: Sum of Elements With Frequency Divisible by K
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/12/2025, 3:52:40 PM
 * Link: https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/
 */

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        int ans = 0;
        for(auto it : freq){
            if(it.second % k == 0){
                ans += it.first * it.second;
            }
        }

        return ans;
    }
};
