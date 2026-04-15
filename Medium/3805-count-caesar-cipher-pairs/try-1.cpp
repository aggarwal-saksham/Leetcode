/*
 * Problem #3805: Count Caesar Cipher Pairs
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/11/2026, 5:36:44 PM
 * Link: https://leetcode.com/problems/count-caesar-cipher-pairs/
 */

class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        long long cnt = 0;
        unordered_map<string, int> mpp;

        for(int i = 0; i < n; i++){
            string w = words[i];
            string key = "";
            for(int j = 0; j < m; j++){
                int d = (w[j] - w[0] + 26) % 26;
                key.push_back(d + 'a');
            }
            mpp[key]++;
        }
        for(auto &p : mpp){
            long long x = p.second;
            cnt += x * (x - 1) / 2;
        } 
        return cnt;
    }
};

