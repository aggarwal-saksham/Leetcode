/*
 * Problem #4035: Maximum Valid Split Positions I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/29/2026, 8:25:51 PM
 * Link: https://leetcode.com/problems/maximum-valid-split-positions-i/
 */

class Solution {
public:
    int helper(vector<int> arr){
        int n = arr.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefix[i] = gcd(prefix[i - 1], arr[i]);
        }
        suffix[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = gcd(suffix[i + 1], arr[i]);
        }

        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            if(prefix[i] == suffix[i + 1]) cnt++;
        }
        return cnt;
    }
    int maxValidSplits(vector<int>& nums) {
        int m = nums.size();
        int best = helper(nums);
        for(int i = 0; i < m; i++){
            vector<int> arr;
            for(int j = 0; j < m; j++){
                if(j != i) arr.push_back(nums[j]);
            }
            best = max(best, helper(arr));
        }
            

        
        return best;
        
    }
};
