/*
 * Problem #2873: Maximum Value of an Ordered Triplet I
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 4/2/2025, 2:44:18 PM
 * Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/
 */

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    maxi = max(maxi, ((nums[i] - nums[j]) * 1LL * nums[k] ));
                }
            }
        }
        return maxi;
    }
};
