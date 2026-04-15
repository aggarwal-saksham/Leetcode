/*
 * Problem #1046: Last Stone Weight
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/5/2026, 5:22:27 PM
 * Link: https://leetcode.com/problems/last-stone-weight/
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        for(int i = 0; i < stones.size(); i++){
            maxH.push(stones[i]);
        }
        while(maxH.size() > 1){
            int x = maxH.top();
            maxH.pop();
            int y = maxH.top();
            maxH.pop();
            if(x - y != 0) maxH.push(x-y);
        }
        return(maxH.size() == 1) ? maxH.top() : 0;
    }
};
