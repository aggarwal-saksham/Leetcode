/*
 * Problem #451: Sort Characters By Frequency
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 1:21:44 AM
 * Link: https://leetcode.com/problems/sort-characters-by-frequency/
 */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(char c : s){
            mpp[c]++;
        }

        vector<pair<int, char>> v;
        for(auto it : mpp){
            v.push_back({it.second, it.first});

        }
        sort(v.rbegin(), v.rend());

        string ans = "";
        for(auto i : v){
            int freq = i.first;
            char ch = i.second;
            while(freq > 0){
                ans += ch;
                freq--;
            }
        }
        return ans;
    }
};
