/*
 * Problem #3833: Count Dominant Indices
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/8/2026, 4:58:52 PM
 * Link: https://leetcode.com/problems/count-dominant-indices/
 */

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int avg = 0, sum = 0, ans = 0;
        for(int i = n - 1; i > 0; i--){
            sum += nums[i];
            avg = sum / (n - i);
            if(avg < nums[i - 1]) ans++;
        }
        return ans;    }
};
