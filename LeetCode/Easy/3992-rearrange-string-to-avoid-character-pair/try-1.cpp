/*
 * Problem #3992: Rearrange String to Avoid Character Pair
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/18/2026, 11:30:19 PM
 * Link: https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/
 */

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<int, int> mpp;
        for(char c : s){
            mpp[c]++;
        }

        string t = "";
        while(mpp[y] > 0){
            t += y;
            mpp[y]--;
        }
        for(auto it : mpp){
            while(it.second--){
                t+= it.first;
            }
        }
        return t;
    }
};
