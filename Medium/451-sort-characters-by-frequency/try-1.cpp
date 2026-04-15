/*
 * Problem #451: Sort Characters By Frequency
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/23/2025, 2:23:45 PM
 * Link: https://leetcode.com/problems/sort-characters-by-frequency/
 */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(char c : s){
            mpp[c]++;
        }

        typedef pair<int, char> pic;
        priority_queue<pic> maxH;

        for(auto i : mpp){
            maxH.push({i.second, i.first});
        }
        
        string ans = "";

        while(!maxH.empty()){
            int freq = maxH.top().first; 
            while(freq > 0){
                ans += (maxH.top().second);
                freq--;
            }
            maxH.pop();
        }

        return ans;

    }
};
