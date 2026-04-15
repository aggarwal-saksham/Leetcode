/*
 * Problem #215: Kth Largest Element in an Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/20/2025, 8:29:52 PM
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> minH;
       int size = 0;
        for(int i = 0; i < nums.size(); i++){
            minH.push(nums[i]);
            size++;
            if(size > k) minH.pop();
        }
        return minH.top();
    }
};
