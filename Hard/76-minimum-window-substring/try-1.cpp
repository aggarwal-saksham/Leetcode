/*
 * Problem #76: Minimum Window Substring
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2025, 7:57:30 PM
 * Link: https://leetcode.com/problems/minimum-window-substring/
 */

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        unordered_map<char, int> mpp;

        for (char c : t) {
            mpp[c]++;
        }

        int l = 0, r = 0;
        int mini = 1e5;
        int cnt = 0;
        int start = -1;
        string ans = "";
        while (r < n) {
            if (mpp[s[r]] > 0) {
                cnt++;
            }
            mpp[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return mini == 1e5 ? "" : s.substr(start, mini);
    }
};
