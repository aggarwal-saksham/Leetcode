/*
 * Problem #846: Hand of Straights
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/29/2026, 12:34:59 AM
 * Link: https://leetcode.com/problems/hand-of-straights/
 */

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) 
            return false;

        unordered_map<int, int> mpp;
        for(int h : hand){
            mpp[h]++;
        }
        for(auto card: hand){
            int start = card;
            while(mpp[start - 1]){
                start--;
            }
            while(start <= card){
                while(mpp[start]){
                    for(int i = start; i < start + groupSize; i++){
                        if(!mpp[i]) return false;

                        mpp[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};
