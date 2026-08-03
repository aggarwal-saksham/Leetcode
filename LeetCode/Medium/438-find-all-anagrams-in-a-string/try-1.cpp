/*
 * Problem #438: Find All Anagrams in a String
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/3/2026, 2:06:30 PM
 * Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m > n) return {};
        vector<int> mapP(26, 0);
        vector<int> mapS(26, 0);
        for(char c : p){
            mapP[c - 'a']++;
        }
        int l = 0, r = 0;
        while(r < m){
            char c = s[r];
            mapS[c - 'a']++;
            r++;
        }
        vector<int> ans;
        while(l < n && r < n){
            if(mapP == mapS) ans.push_back(l);
            mapS[s[l] - 'a']--;
            l++;
            mapS[s[r] - 'a']++;  
            if(r < n) r++;
        }
        if(mapP == mapS) ans.push_back(l);

        return ans;
    }
};
