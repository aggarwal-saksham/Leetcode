/*
 * Problem #18: 4Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/10/2026, 3:11:13 PM
 * Link: https://leetcode.com/problems/4sum/
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int h = 0; h < n - 3; h++){
            for(int i = h + 1; i < n - 2; i++){
                int j = i + 1, k = n - 1;
                while(j < k){
                    long long sum = 0LL + nums[h] + nums[i] + nums[j] + nums[k];
                    if(sum == target){
                        vector<int> quad = {nums[h], nums[i], nums[j], nums[k]};
                        s.insert(quad);
                        k--;
                        j++;
                    }
                    else if(sum > target){
                        k--;
                    }
                    else j++;

                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
