/*
 * Problem #2185: Counting Words With a Given Prefix
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/9/2025, 6:09:03 PM
 * Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/
 */

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(string word : words){
            if(word.substr(0, pref.length()) == pref) cnt++;
        }
        return cnt;
    }
};
