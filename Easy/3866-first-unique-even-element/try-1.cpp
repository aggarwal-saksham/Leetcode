/*
 * Problem #3866: First Unique Even Element
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/20/2026, 7:55:30 PM
 * Link: https://leetcode.com/problems/first-unique-even-element/
 */

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums){
            freq[n]++;
        }
        for(int n : nums){
            if(freq[n] == 1 && (n & 1) == 0) return n;
        }
        return -1;
    }
};
