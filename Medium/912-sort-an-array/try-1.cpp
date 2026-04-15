/*
 * Problem #912: Sort an Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/21/2025, 1:06:23 AM
 * Link: https://leetcode.com/problems/sort-an-array/
 */

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minH;
        vector<int> ans;
        for(int i : nums){
            minH.push(i);
        }
        while(!minH.empty()){
            ans.push_back(minH.top());
            minH.pop();
        }
        return ans;
    }
};
