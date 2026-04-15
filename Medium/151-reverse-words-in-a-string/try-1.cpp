/*
 * Problem #151: Reverse Words in a String
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/16/2024, 12:37:27 AM
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 */

class Solution {
public:
    string reverseWords(string s) {
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++){
            string word;
            if(s[i] == ' ') continue;
            while(i < s.size() && s[i] != ' ' ){
                word += s[i]; 
                i++;

            }
            stack.push(word);



        }
        while(!stack.empty()){
            result += stack.top();
            stack.pop();
            if(!stack.empty()) result += ' ';

        }
        return result;
    }
};
