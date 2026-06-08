/*
 * Problem #17: Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 2:04:15 AM
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
public:
    void backtrack(string digits, int i, string &curr, vector<string> &phone_map, vector<string> &ans){
        if(i == digits.length()){
            ans.push_back(curr);
            return;
        }

        string letters = phone_map[digits[i] - '0'];
        for(int j = 0; j < letters.length(); j++){
            curr.push_back(letters[j]);
            backtrack(digits, i + 1, curr, phone_map, ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> phone_map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string curr = "";
        backtrack(digits, 0, curr, phone_map, ans);
        return ans;

    }
};
