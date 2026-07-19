/*
 * Problem #3998: Transform Binary String Using Subsequence Sort
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/19/2026, 8:43:45 AM
 * Link: https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/
 */

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        //11010100101
        //
        int n = s.size();
        int zeros = 0;
        for(char c : s){
            if(c == '0') zeros++;
        }

        vector<int> pref(n + 1);
        for(int i  =0; i < n; i++){
            if(s[i] == '0') pref[i + 1] = pref[i] + 1;
            else pref[i + 1] = pref[i];
        }

        vector<bool> ans;

        for(string &str : strs){
            int z = 0, q = 0;
            for(char c: str){
                if(c == '0') z++;
                else if(c == '?') q++;
            }

            if(z > zeros || z + q < zeros){
                ans.push_back(false);
                continue;
            }


            int req = zeros - z;
            int cnt = 0;
            bool flag = true;

            for(int i = 0; i < n; i++){
                if(str[i] == '0'){
                    cnt++;
                }
                else if(str[i] == '?' && req){
                    cnt++;
                    req--;
                }

                if(cnt < pref[i + 1]){
                    flag = false;
                    break;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};
