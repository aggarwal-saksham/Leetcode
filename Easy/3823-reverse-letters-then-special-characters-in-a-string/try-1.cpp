/*
 * Problem #3823: Reverse Letters Then Special Characters in a String
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/31/2026, 8:05:37 PM
 * Link: https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/
 */

class Solution {
public:
    string reverseByType(string s) {
        stack<char> spc;
        stack<char>lower;
        for(char c : s){
            if(isalpha(c)) lower.push(c);
            else spc.push(c);
            
        }
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                char c = lower.top();
                lower.pop();
                s[i] = c;
                    
            }
            else{
                char c = spc.top();
                spc.pop();
                s[i] = c;
            }
        }
        return s;
    }
};
