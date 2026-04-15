/*
 * Problem #1394: Find Lucky Integer in an Array
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 12:18:56 PM
 * Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/
 */

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), greater<int>());
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(arr[i - 1] == arr[i]) cnt++;
            else{
                if (cnt == arr[i - 1]) return cnt;
                cnt = 1;
            }
        }

        if (cnt == arr[n - 1]) return cnt;
        return -1;
    }
};
