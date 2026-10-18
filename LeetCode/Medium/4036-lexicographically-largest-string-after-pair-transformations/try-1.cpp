/*
 * Problem #4036: Lexicographically Largest String After Pair Transformations
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/29/2026, 8:53:29 PM
 * Link: https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/
 */

class Solution {
public:
    string helper(int x){
        vector<int> digits(26, 0);
        for(int l = 0; l < 25; l++){
            digits[l] = x % 2;
            x /= 2;
        }
        digits[25] = x;

        string res = "";
        for(int l = 25; l >= 0; l--){
            for(int k = 0; k < digits[l]; k++){
                res += l + 'a';
            }
        }
        return res;
    }
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int x : nums){
            ans.push_back(helper(x));
        }
        return ans;
    }
};
