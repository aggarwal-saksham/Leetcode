/*
 * Problem #338: Counting Bits
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/15/2026, 11:04:09 PM
 * Link: https://leetcode.com/problems/counting-bits/
 */

class Solution {
public:
    int setBits(int n) {
       int cnt = 0;
       while(n > 0){
        if(n & 1) cnt++;
        n >>= 1;
       }
       return cnt; 
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(setBits(i));
        }
        return ans;
    }
};
