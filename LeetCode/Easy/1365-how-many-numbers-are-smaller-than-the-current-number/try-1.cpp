/*
 * Problem #1365: How Many Numbers Are Smaller Than the Current Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/5/2026, 5:14:17 PM
 * Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //1 2 1 1
        //0 1 3 4 
        vector<int> freq(101, 0);
        for(int n : nums){
            freq[n]++;
        }
        int pre = 0;

        for(int i = 0; i < 101; i++){
            int t = freq[i];
            freq[i] = pre;
            pre += t;
            // cout << freq[i] << " ";
        }
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = freq[nums[i]];
        }
        return ans;
    }
};
