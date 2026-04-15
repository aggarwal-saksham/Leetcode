/*
 * Problem #229: Majority Element II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2025, 4:44:10 PM
 * Link: https://leetcode.com/problems/majority-element-ii/
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        //11133222

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1++;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){
                cnt2++;
                el2 = nums[i];
            }

            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;

            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for(int num : nums){
            if(num == el1) cnt1++;
            if(num == el2) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > floor(n/3)) ans.push_back(el1);
        if(cnt2 > floor(n/3)) ans.push_back(el2);

        return ans;
    }
};
