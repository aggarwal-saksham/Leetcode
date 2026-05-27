/*
 * Problem #556: Next Greater Element III
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/14/2026, 3:25:25 PM
 * Link: https://leetcode.com/problems/next-greater-element-iii/
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                ind = i - 1;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i > ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
    }
    int nextGreaterElement(int n) {
        
        vector<int> nums;

        int x = n;

        while(x > 0){
            nums.push_back(x % 10);
            x /= 10;
        }

        reverse(nums.begin(), nums.end());

        nextPermutation(nums);

        long long ans = 0;

        for(int i = 0; i < nums.size(); i++){
            ans = ans * 10 + nums[i];
        }

        if(ans <= n || ans > INT_MAX) return -1;

        return (int)ans;
    }
};
