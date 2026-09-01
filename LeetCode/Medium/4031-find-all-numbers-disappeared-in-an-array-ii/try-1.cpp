/*
 * Problem #4031: Find All Numbers Disappeared in an Array II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/29/2026, 3:59:33 PM
 * Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/
 */

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(lower == upper) {
            if(!binary_search(nums.begin(), nums.end(), lower))
                ans.push_back({lower, upper});
            return ans;
        }
        nums.push_back(lower);
        nums.push_back(upper);
        sort(nums.begin(), nums.end());

        int p1 = upper_bound(nums.begin(), nums.end(), lower) - nums.begin() - 1;
        int p2 = lower_bound(nums.begin(), nums.end(), upper) - nums.begin();
        int n = nums.size();
        for(int i = p1; i < p2; i++){
            int s =nums[i] + 1;
            int e = nums[i + 1] - 1;
            if(i == p1){                
                if(i > 0 && nums[i] == nums[i - 1]) ;
                else s = nums[i];
            }
            if(i == p2 - 1){
                if(i < n - 2 && nums[i + 1] == nums[i + 2]) ;
                else e = nums[i + 1];
            }

            if(s <= e) ans.push_back({s, e});
        }
        return ans;
        
    }
};
