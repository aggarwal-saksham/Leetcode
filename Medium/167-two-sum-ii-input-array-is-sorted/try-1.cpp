/*
 * Problem #167: Two Sum II - Input Array Is Sorted
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/30/2025, 4:32:38 PM
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                return {l + 1, r + 1};
            }
            else if(numbers[l] + numbers[r] < target){
                l++;
            }
            else r--;
        }
        return {-1, -1};
    }
};
