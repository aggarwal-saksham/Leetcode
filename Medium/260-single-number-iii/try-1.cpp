/*
 * Problem #260: Single Number III
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/1/2024, 12:19:14 AM
 * Link: https://leetcode.com/problems/single-number-iii/
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i = 0; i < nums.size(); i++){
            xorr = xorr ^ nums[i];

        }
        int rightset = (xorr & (-(unsigned int)xorr)) ;
        int b1 = 0, b2 = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & rightset) b1 = b1 ^ nums[i];
            else b2 = b2 ^ nums[i];
        }
        //vector<int> ans;
        //ans.push_back(b1);
        //ans.push_back(b2);
        return {b1,b2};

        
    }
};
