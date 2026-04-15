/*
 * Problem #71: Simplify Path
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/7/2025, 1:01:58 AM
 * Link: https://leetcode.com/problems/simplify-path/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        string s = "";
        while (i < path.size()) {
            if (path[i] == '/') {
                if (!s.empty()) {
                    if (s == "..") {
                        if (!st.empty()) st.pop();
                    } else if (s != ".") {
                        st.push(s);
                    }
                }
                s = "";
                i++;
            } else {
                s += path[i];
                i++;
            }
        }
        if (!s.empty()) {
            if (s == "..") {
                if (!st.empty()) st.pop();
            } else if (s != ".") {
                st.push(s);
            }
        }
        vector<string> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        string res = "/";
        for (int j = 0; j < v.size(); j++) {
            res += v[j];
            if (j + 1 < v.size()) res += "/";
        }
        return res;
    }
};

