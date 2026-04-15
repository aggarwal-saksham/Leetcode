/*
 * Problem #35: Search Insert Position
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2024, 11:51:48 PM
 * Link: https://leetcode.com/problems/search-insert-position/
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
		int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
             if(target <= nums[mid]){
				ans = mid;
                high = mid - 1;
            }
            else  {
                low = mid + 1;
            }
			
        }
        return ans;
        
    }
};
