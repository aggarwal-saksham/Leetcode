/*
 * Problem #1331: Rank Transform of an Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/29/2026, 12:09:09 AM
 * Link: https://leetcode.com/problems/rank-transform-of-an-array/
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> ranks;
        set<int> st(arr.begin(), arr.end());
        int r = 1;
        for(auto it : st){
            ranks[it] = r;
            r++;
        }

        for(int i = 0; i < arr.size(); i++){
            arr[i] = ranks[arr[i]];
        }
        return arr;

    }
};
