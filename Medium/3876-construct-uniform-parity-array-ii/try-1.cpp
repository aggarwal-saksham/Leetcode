/*
 * Problem #3876: Construct Uniform Parity Array II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/24/2026, 10:43:38 AM
 * Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/
 */

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         int mn = *min_element(nums1.begin(), nums1.end());
        bool odd = false, even = false;

        for(int x : nums1){
            if(x & 1) odd = true;
            else even = true;
        }

        if(!odd || !even) return true;

        return (mn & 1);
    }
};
