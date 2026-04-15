/*
 * Problem #1464: Maximum Product of Two Elements in an Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/21/2025, 1:13:09 AM
 * Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minH;
        for(int num : nums){
            minH.push(num);
            if(minH.size() > 2){
                minH.pop();
            }

        }
        int x = minH.top() - 1;
        minH.pop();
        int y = minH.top() - 1;
        return x*y;
    }
};
