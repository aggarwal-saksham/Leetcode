/*
 * Problem #3955: Valid Binary Strings With Cost Limit
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/7/2026, 8:12:47 AM
 * Link: https://leetcode.com/problems/valid-binary-strings-with-cost-limit/
 */

class Solution {
public:
    vector<string> result;

    void generate(int n, string curr, int idx, int cost, int k) {
        if (cost > k) return;

        if (idx == n) {
            result.push_back(curr);
            return;
        }

        generate(n, curr + '0', idx + 1, cost, k);

        if (curr.empty() || curr.back() != '1') {
            generate(n, curr + '1', idx + 1, cost + idx, k);
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        auto lavomirex = make_pair(n, k);

        generate(n, "", 0, 0, k);
        return result;
    }
};
