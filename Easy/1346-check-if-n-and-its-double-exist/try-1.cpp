/*
 * Problem #1346: Check If N and Its Double Exist
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/30/2024, 11:27:53 PM
 * Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target <= nums[mid]){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
        
    }
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
           int bs1 = search(arr, arr[i] * 2);
          // bool bs2 = search(arr, arr[i] / 2);

           if(bs1 != -1 && bs1 != i) return true;
        }
        return false;

    }
};
