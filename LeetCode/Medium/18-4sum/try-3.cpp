/*
 * Problem #18: 4Sum
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/10/2026, 3:16:04 PM
 * Link: https://leetcode.com/problems/4sum/
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int h = 0; h < n - 3; h++){
            if(h > 0 && nums[h] == nums[h - 1]) continue;
            for(int i = h + 1; i < n - 2; i++){
                if(i > h + 1 && nums[i] == nums[i  -1]) continue;
                int j = i + 1, k = n - 1;
                while(j < k){
                    long long sum = 0LL + nums[h] + nums[i] + nums[j] + nums[k];
                    if(sum == target){
                        vector<int> quad = {nums[h], nums[i], nums[j], nums[k]};
                        ans.push_back(quad);
                        k--;
                        j++;
                        while(j < k && nums[j] == nums[j-1]) j++; 
                        while(j < k && nums[k] == nums[k+1]) k--;
                    }
                    else if(sum > target){
                        k--;
                    }
                    else j++;

                }
            }
        }
        return ans;
    }
};
