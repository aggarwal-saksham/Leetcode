/*
 * Problem #2425: Bitwise XOR of All Pairings
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/17/2025, 4:13:44 PM
 * Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/
 */

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int xor1 = 0;
        int xor2 = 0;
        for(int i = 0; i < n1; i++){
            xor1 ^= nums1[i];
        }
        for(int i = 0; i < n2; i++){
            xor2 ^= nums2[i];
        }
        int ans = 0;
        while(n1){
            ans ^= xor2;
            n1--;
        }
        while(n2){
            ans ^= xor1;
            n2--;
        }
        return ans;
    }
};
