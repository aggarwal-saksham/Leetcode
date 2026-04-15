/*
 * Problem #2138: Divide a String Into Groups of Size k
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 11:14:25 AM
 * Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
 */

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();

        int i = 0;
        while (i < s.size()) {
            string group = "";
            if (i + k - 1 < n)
                group = s.substr(i, k);
            else if (i < n) {
                group = s.substr(i);
                int grpLen = group.size();
                int toAdd = k - grpLen;
                while (toAdd) {
                    group += fill;
                    toAdd--;
                }
            }
            ans.push_back(group);
            i += k;
        }

        return ans;
    }
};
