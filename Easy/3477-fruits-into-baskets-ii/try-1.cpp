/*
 * Problem #3477: Fruits Into Baskets II
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/5/2025, 3:58:45 PM
 * Link: https://leetcode.com/problems/fruits-into-baskets-ii/
 */

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        for(int  f : fruits){
            for(int &b : baskets){
                if(f <= b){
                    cnt++;
                    b = -1;
                    break;
                } 
            }
        }

        return fruits.size() - cnt;        
    }
};
