/*
 * Problem #3824: Minimum K to Reduce Array Within Limit
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/31/2026, 8:21:48 PM
 * Link: https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/
 */

class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long l = 1, h = 1e5;
        int ans = 0;
        while(l <= h){
            long long mid = (l + h) / 2;
            long long total = 0;

            for(int x : nums){
                total += (x + mid - 1) / mid;
                
            }

            if(total <= mid * mid){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
            
        }

        return ans;
    }
};
