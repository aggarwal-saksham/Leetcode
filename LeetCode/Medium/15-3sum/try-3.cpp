/*
 * Problem #15: 3Sum
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/10/2026, 2:53:25 PM
 * Link: https://leetcode.com/problems/3sum/
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i  -1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    ans.push_back(triplet);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++; 
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }
                else j++;
            }
        }
        return ans;
    }
};
