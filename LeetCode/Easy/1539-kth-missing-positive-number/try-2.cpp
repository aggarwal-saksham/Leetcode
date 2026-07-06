/*
 * Problem #1539: Kth Missing Positive Number
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/6/2026, 1:58:43 PM
 * Link: https://leetcode.com/problems/kth-missing-positive-number/
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] <= k) k++;
            else return k; 
        }
        return k;
    }
};
