/*
 * Problem #3136: Valid Word
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/15/2025, 1:41:37 PM
 * Link: https://leetcode.com/problems/valid-word/
 */

class Solution {
public:
    bool isValid(string word) {
        set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        if (word.length() < 3)
            return false;
        bool findVowel = false, findCons = false;
        for (char c : word) {
            if (!isalnum(c))
                return false;

            if (isdigit(c))
                continue;

            if (isalpha(c)) {
                if (vowel.find(c) != vowel.end() ||
                    vowel.find(c - 'A' + 'a') != vowel.end()) {
                    findVowel = true;
                }
                else findCons = true;
            }
        }

        return (findVowel && findCons);
    }
};
