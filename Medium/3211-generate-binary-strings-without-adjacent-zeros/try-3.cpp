/*
 * Problem #3211: Generate Binary Strings Without Adjacent Zeros
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/7/2026, 6:03:28 PM
 * Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/
 */

class Solution {
public:
    vector<string> result;
    void generate(int n, string &curr) {
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }
        curr.push_back('1');
        generate(n, curr);
        curr.pop_back();

        if (curr.empty() || curr.back() != '0') {
            curr.push_back('0');
            generate(n, curr);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string curr = "";
        generate(n, curr);
        return result;
    }
};
