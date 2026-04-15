/*
 * Problem #18: 4Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 2:15:54 PM
 * Link: https://leetcode.com/problems/4sum/
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 4) return {};
        set<vector<int>> ans;
        long long sum = 0;
        //-4 -1 -1 0 1 2
        for (int h = 0; h < n - 3; h++) {

            for (int i = h + 1; i < n - 2; i++) {

                int j = i + 1;
                int k = n - 1;

                while (j < k) {
                    sum = 1LL * nums[h] + nums[i] + nums[j] + nums[k];
                    if (sum < target) {
                        j++;
                    }
                    else if (sum > target) {
                        k--;
                    } 
                    else {
                        ans.insert({nums[h], nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                    }
                }
            }
        }

        vector<vector<int>> ansmain;

        for (auto it : ans) {
            ansmain.push_back(it);
        }

        return ansmain;
    }
};
