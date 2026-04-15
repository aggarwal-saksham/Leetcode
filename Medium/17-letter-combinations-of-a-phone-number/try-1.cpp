/*
 * Problem #17: Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/16/2025, 3:07:05 PM
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution
{
    public:
        void helper(int i, string digits, vector<string> phone_map, string comb, vector<string> &ans)
        {

            if (i == digits.length())
            {
                ans.push_back(comb);
                return;
            }
            string letters = phone_map[digits[i] - '2'];
            for (int j = 0; j < letters.length(); j++) 
            {
                comb.push_back(letters[j]);
                helper(i + 1, digits, phone_map, comb, ans);
                comb.pop_back();
            }
        }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        vector<string> phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string comb = "";
        helper(0, digits, phone_map, comb, ans);
        return ans;
    }
};
