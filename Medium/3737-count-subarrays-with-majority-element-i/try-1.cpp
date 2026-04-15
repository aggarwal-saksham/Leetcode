/*
 * Problem #3737: Count Subarrays With Majority Element I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/22/2025, 1:00:16 AM
 * Link: https://leetcode.com/problems/count-subarrays-with-majority-element-i/
 */

class Solution {
public:
    
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //2 2 2 2 3 4 5
        int n = nums.size();
        int  ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == target) cnt++;

                if(cnt > (j - i + 1) / 2) ans++;
            }
            
        }
        return ans;
    }
};
