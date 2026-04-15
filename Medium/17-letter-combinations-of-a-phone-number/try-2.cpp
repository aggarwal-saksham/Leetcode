/*
 * Problem #17: Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 2/23/2026, 8:00:30 PM
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution
{
    public:

    void helper(int idx, string &digits, vector<string> &phone_map, string &comb, vector<string> &ans){
        if(idx == digits.length()){
            ans.push_back(comb);
            return;

        }

        string letters = phone_map[digits[idx] - '0'];
        for(int j = 0; j < letters.length(); j++){
            comb += letters[j];
            helper(idx + 1, digits, phone_map, comb, ans);
            comb.pop_back();
        }



    }
        
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        vector<string> phone_map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string comb = "";
        helper(0, digits, phone_map, comb, ans);
        return ans;
    }
};
