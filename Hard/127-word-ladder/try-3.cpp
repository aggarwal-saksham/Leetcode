/*
 * Problem #127: Word Ladder
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/18/2026, 9:09:26 PM
 * Link: https://leetcode.com/problems/word-ladder/
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);

        queue<pair<string, int>> q; 
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0; i < word.size(); i++){
                char orig = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};
