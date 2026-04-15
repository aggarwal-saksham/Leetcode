/*
 * Problem #2348: Number of Zero-Filled Subarrays
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/19/2025, 10:18:55 PM
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
            }
            else{
                ans += (zeroes * (zeroes + 1LL) / 2LL);
                zeroes = 0;
            }
        }
        ans += (zeroes * (zeroes + 1LL) / 2LL);

        return ans;
    }
};
