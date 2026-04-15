/*
 * Problem #2966: Divide Array Into Arrays With Max Difference
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/18/2025, 1:57:03 PM
 * Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
 */

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i < n){
            vector<int> arr;
            arr.push_back(nums[i]);
            arr.push_back(nums[i + 1]);
            arr.push_back(nums[i + 2]);
            ans.push_back(arr);
            i += 3;
        }

        for(int i = 0; i < ans.size(); i++){
            if(ans[i][2] - ans[i][0] <= k) continue;
            else return {};
        }

        return ans;
    }
};
