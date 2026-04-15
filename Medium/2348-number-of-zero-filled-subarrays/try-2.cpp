/*
 * Problem #2348: Number of Zero-Filled Subarrays
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/19/2025, 10:22:26 PM
 * Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/
 */

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        /*
        1=1
        2=3
        3=6
        4=20
        n=(n*(n+1))/2
        */

        long long ans = 0;
        long long zeroes = 0;
        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 0){
                zeroes++;
                ans += zeroes;
            }
            else{
                zeroes = 0;
            }
        }
        
        return ans;
    }
};
