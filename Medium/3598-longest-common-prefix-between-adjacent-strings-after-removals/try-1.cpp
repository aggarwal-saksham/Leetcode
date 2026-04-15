/*
 * Problem #3598: Longest Common Prefix Between Adjacent Strings After Removals
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2025, 3:39:59 PM
 * Link: https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/
 */

class Solution {
public:
    int lcp(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int i = 0, j = 0;
        int len = 0;
        while (i < n1 && j < n2) {
            if (s1[i] == s2[j])
                len++;
            else
                break;
            i++;
            j++;
        }

        return len;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n, 0);

        if(n == 1) {
            return ans;
        }

        vector<int> allLCP(n - 1);

        for (int i = 0; i < n - 1; i++) {
            allLCP[i] = lcp(words[i], words[i + 1]);
        }

        vector<int> prefmax(n - 1), sufmax(n - 1);
        prefmax[0] = allLCP[0];
        for (int i = 1; i < n - 1; i++) {
            prefmax[i] = max(prefmax[i - 1], allLCP[i]);
        }

        sufmax[n - 2] = allLCP[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            sufmax[i] = max(sufmax[i + 1], allLCP[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = (i + 1 <= n - 2) ? sufmax[i + 1] : 0;
            } 
            else if (i == n - 1) {
                ans[i] = (i - 2 >= 0) ? prefmax[i - 2] : 0;
            } 
            else if (i > 0 && i < n - 1) {
                int newLCP = lcp(words[i - 1], words[i + 1]);
                int prev = (i - 2 >= 0) ? prefmax[i - 2] : 0;
                int next = (i + 1 <= n - 2) ? sufmax[i + 1] : 0;

                ans[i] = max({newLCP, prev, next});
            }
        }

        return ans;
    }
};
