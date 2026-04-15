/*
 * Problem #2785: Sort Vowels in a String
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/11/2025, 6:14:41 PM
 * Link: https://leetcode.com/problems/sort-vowels-in-a-string/
 */

class Solution {
public:
    bool isVowel(char c) {
        
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        return false;
    }
    string sortVowels(string s) {
        string vowels = "";
        for(char c : s){
            if(isVowel(c)) vowels += c;
        }
        sort(vowels.begin(), vowels.end());
        string t = "";
        int l = 0;
        for(char c : s){
            if(isVowel(c)){
                t += vowels[l];
                l++;
            }
            else{
                t += c;
            }
        }
        return t;
    }
};
