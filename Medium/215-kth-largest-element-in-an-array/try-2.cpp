/*
 * Problem #215: Kth Largest Element in an Array
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2025, 3:24:29 PM
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> minH;
       
        for(int i = 0; i < nums.size(); i++){
            minH.push(nums[i]);
            if(minH.size() > k) minH.pop();
        }
        return minH.top();
    }
};
