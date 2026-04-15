/*
 * Problem #3788: Maximum Score of a Split
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/28/2025, 2:26:04 PM
 * Link: https://leetcode.com/problems/maximum-score-of-a-split/
 */

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        vector<int> suffixMin(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = (long long)nums[i] + prefixSum[i - 1];
        }
        suffixMin[n - 1] = nums[n  -1];
        int mini = suffixMin[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            mini = min(suffixMin[i + 1], nums[i+1]);
            suffixMin[i] = mini;    
        }
        long long ans = LLONG_MIN;
        for(int i = 0; i < n - 1; i++){
            ans = max(ans, prefixSum[i] - (long long)suffixMin[i]);
        }
        return ans;
    }
};
