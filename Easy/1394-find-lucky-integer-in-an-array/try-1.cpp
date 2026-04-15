/*
 * Problem #1394: Find Lucky Integer in an Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 12:08:31 PM
 * Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/
 */

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for( int num : arr){
            freq[num]++;
        }

        int maxi = -1;

        for(auto i : freq){
            if(i.first == i.second){
                maxi = max(maxi, i.first);
            }
        }

        return maxi;
    }
};
