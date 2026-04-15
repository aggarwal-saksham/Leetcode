/*
 * Problem #3795: Minimum Subarray Length With Distinct Sum At Least K
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/4/2026, 3:09:40 PM
 * Link: https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/
 */

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        //1 3 5 8 1 2  9 9 
        //18
        unordered_map<int, int> mpp;
        int n = nums.size();
        int l = 0, r = 0, ans = 1e9;
        long long sum  = 0;
        while(r < n){
            if(mpp[nums[r]] == 0){
               sum += (long long)nums[r];
            } 
            mpp[nums[r]]++;
            while(sum >= k){
                ans = min ( ans, r - l   +1);
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) sum -= nums[l]; 
                l++;
                
            }
            r++;
        }

        return(ans == 1e9) ? -1 : ans;
    }
};
