/*
 * Problem #127: Word Ladder
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/14/2025, 6:05:52 PM
 * Link: https://leetcode.com/problems/word-ladder/
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;

            q.pop();
            if(word == endWord) return steps;

            for(int i = 0; i < word.size(); i++){
                char orig = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = orig;
            }
        }

        return 0;
    }
};



















