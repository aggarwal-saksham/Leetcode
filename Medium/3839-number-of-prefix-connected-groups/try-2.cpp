/*
 * Problem #3839: Number of Prefix Connected Groups
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 2/14/2026, 8:24:14 PM
 * Link: https://leetcode.com/problems/number-of-prefix-connected-groups/
 */

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, vector<string>> mpp;
        int n = words.size();
        for(int i = 0; i < n; i++){
            string &w = words[i];
            if(w.size() >= k){
                mpp[w.substr(0, k)].push_back(w);
            }
        }

        int ans = 0;
        for(auto it : mpp){
            if(it.second.size() > 1) ans++;
        }
        return ans;
    }
};
