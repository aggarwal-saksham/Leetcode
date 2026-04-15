/*
 * Problem #74: Search a 2D Matrix
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/2/2026, 5:29:42 PM
 * Link: https://leetcode.com/problems/search-a-2d-matrix/
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int m = nums.size();
        int n = nums[0].size();
        int low = 0, high = (m * n ) - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int r = mid / n;
            int c = mid % n;
            if(target == nums[r][c]){
                return true;
            }
            else if(target <= nums[r][c]){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
        
    }
};
