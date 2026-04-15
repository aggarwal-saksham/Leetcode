/*
 * Problem #2490: Circular Sentence
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 11/3/2024, 1:53:11 PM
 * Link: https://leetcode.com/problems/circular-sentence/
 */

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if(sentence[0] != sentence[n-1]) return false;
        for(int i = 0; i < n; i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[i+1]) return false;
            }
        }
        return true;
    }
};
