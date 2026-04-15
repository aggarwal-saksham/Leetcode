/*
 * Problem #3211: Generate Binary Strings Without Adjacent Zeros
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/28/2026, 5:16:22 PM
 * Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/
 */

class Solution {
public:
    void backtrack(vector<string> &ans, string s, int i){
        if(i >= s.length()){
            ans.push_back(s);
            return;
        }
        backtrack(ans, s, i + 1);

        s[i] = '0';
        backtrack(ans, s, i + 2);
        s[i] = '1';

    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s(n, '1');
        backtrack(ans, s, 0);
        return ans;
    }
};
