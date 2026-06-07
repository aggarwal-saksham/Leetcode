/*
 * Problem #3211: Generate Binary Strings Without Adjacent Zeros
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/6/2026, 10:58:08 PM
 * Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/
 */

class Solution {
public:
    vector<string> result;
    void generate(int n, string curr) {
        // Base case: if length is n, add to result
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }

        generate(n, curr + "1");

        if (curr.empty() || curr.back() != '0') {
            generate(n, curr + "0");
        }
    }
    vector<string> validStrings(int n) {
        generate(n, "");
        return result;
    }
};
