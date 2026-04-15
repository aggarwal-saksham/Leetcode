/*
 * Problem #567: Permutation in String
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/30/2025, 3:17:14 PM
 * Link: https://leetcode.com/problems/permutation-in-string/
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for(char c : s1){
            freq1[c]++;
        }
        int l = 0, r;
        for( r = 0; r < s1.length(); r++){
            freq2[s2[r]]++;
        }
        r--;
        while(r < s2.length()){
            if(freq1 == freq2) return true;
            freq2[s2[l]]--;
            if(freq2[s2[l]] == 0) freq2.erase(s2[l]);
            l++;
            r++;
            freq2[s2[r]]++;
        }
        return false;
    }
};
