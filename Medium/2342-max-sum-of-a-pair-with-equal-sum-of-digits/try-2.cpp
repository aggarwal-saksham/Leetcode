/*
 * Problem #2342: Max Sum of a Pair With Equal Sum of Digits
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/14/2026, 3:59:46 PM
 * Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
 */

class Solution {
public:
    int sumOfDigits(int number){
        int temp = number;
        int ans = 0;
        while(temp != 0){
            ans += temp%10;
            temp /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
         
        unordered_map<int, priority_queue<pair<int, int>>> mpp;
        for(int i = 0; i < nums.size(); i++){
            int sod = sumOfDigits(nums[i]);
            mpp[sod].push({nums[i], i});

        }

        int maxi = -1;
        for(auto it : mpp){
            int maxsum = 0;
            if(it.second.size() >= 2) {
                int n = 2;
                while(n > 0){
                    maxsum += it.second.top().first;
                    it.second.pop();
                    n--;
                }
            }
            else maxsum = -1;
            maxi = max(maxi, maxsum); 
        }
        return maxi;
    }
};
