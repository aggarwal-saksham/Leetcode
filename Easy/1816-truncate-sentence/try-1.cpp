/*
 * Problem #1816: Truncate Sentence
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/13/2024, 3:43:43 PM
 * Link: https://leetcode.com/problems/truncate-sentence/
 */

class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int cnt = 0;
        for(char c : s){
           if(c == ' ') cnt++;
           if(cnt == k) break;
           ans += c; 
        }
        return ans;
    }
};
