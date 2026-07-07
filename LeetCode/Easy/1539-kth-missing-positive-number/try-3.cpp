/*
 * Problem #1539: Kth Missing Positive Number
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/6/2026, 2:17:07 PM
 * Link: https://leetcode.com/problems/kth-missing-positive-number/
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, h = n - 1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            int missing = arr[mid] - (mid + 1);
            if(missing < k) l = mid + 1;
            else h = mid - 1; 
        }
        return l + k;
    }
};
