/*
 * Problem #1769: Minimum Number of Operations to Move All Balls to Each Box
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/6/2025, 4:07:29 PM
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 */

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;

        for(int i = 0; i < boxes.length(); i++){
            int moves = 0;
            for(int  j = 0; j < boxes.length(); j++){
                if(boxes[j] == '1'){
                    moves += abs(j - i);
                }
            }
            ans.push_back(moves);
        }
        return ans;
    }
};
