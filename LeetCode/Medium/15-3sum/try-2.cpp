/*
 * Problem #15: 3Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/10/2026, 2:14:35 PM
 * Link: https://leetcode.com/problems/3sum/
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    s.insert(triplet);
                    k--;
                    j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else j++;

            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
