/*
 * Problem #3987: Minimum Total Cost to Process All Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2026, 8:30:59 AM
 * Link: https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/
 */

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long mod = 1e9 + 7;
        long long fix = k;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long cnt = 0;

        if(total > k){
            cnt = (total - 1) / k;
        }
        long long cost = 0;
        if(cnt % 2 == 0) {
            cost = ((cnt / 2) % mod) * ((cnt + 1) % mod) % mod;
            
        }
        else{
            cost = ((cnt) % mod) * (((cnt + 1) / 2) % mod) % mod;
            
        }
        // while(fix < total){
        //     fix = fix + k;
        //     cnt++;
        //     cost =( cost + cnt) % mod;
        // }
        return (int)cost;
        
    }
};
