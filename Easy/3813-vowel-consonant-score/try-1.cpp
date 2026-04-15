/*
 * Problem #3813: Vowel-Consonant Score
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/18/2026, 6:39:48 PM
 * Link: https://leetcode.com/problems/vowel-consonant-score/
 */

class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, cons = 0;
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                v++;
            }
            else if(!isdigit(c) && c != ' '){
                cons++;
            }

        }
            return (cons > 0) ? (v/cons) : 0;
    }
};
