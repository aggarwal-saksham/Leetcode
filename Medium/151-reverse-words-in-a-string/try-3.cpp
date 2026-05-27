/*
 * Problem #151: Reverse Words in a String
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/26/2026, 11:57:11 PM
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 */

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string result = "";
        int i = 0;
        int n = s.length();
        while(i < n){
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            if(word != ""){
                st.push(word);
            }
            i++;
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
            if(!st.empty()) result += ' ';

        }
        return result;
    }
};
