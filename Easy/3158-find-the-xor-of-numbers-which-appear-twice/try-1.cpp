/*
 * Problem #3158: Find the XOR of Numbers Which Appear Twice
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/1/2024, 3:09:05 PM
 * Link: https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/
 */

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i= 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int xorr = 0;
        for(auto it: mp){
            if(it.second == 2) xorr = xorr ^ it.first;
        }
        return xorr;
        
    }
};
