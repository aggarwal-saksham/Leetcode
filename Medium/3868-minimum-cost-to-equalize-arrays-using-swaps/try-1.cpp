/*
 * Problem #3868: Minimum Cost to Equalize Arrays Using Swaps
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/20/2026, 8:28:45 PM
 * Link: https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/
 */

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            freq1[nums1[i]]++;
            freq1[nums2[i]]--;
        }
        int ans = 0;
        for(auto it : freq1){
            if(it.second % 2 != 0) return -1;
            ans += abs(it.second);
        }
        
        return ans / 4;
    }
};
