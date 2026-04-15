/*
 * Problem #1455: Check If a Word Occurs As a Prefix of Any Word in a Sentence
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/12/2024, 2:12:19 PM
 * Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
 */

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n1 = searchWord.size();
        int cnt = 1;
        for(int i = 0; i < sentence.size(); i++){
            string sub = sentence.substr(i,n1);
            if(sub == searchWord && i == 0) return 1;
            if(sentence[i] == ' ') cnt++;
            if((sub == searchWord && sentence[i-1] == ' ')) return cnt;
        }
        return -1;
    }
};
