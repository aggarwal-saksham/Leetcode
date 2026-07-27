/*
 * Problem #3913: Sort Vowels by Frequency
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/25/2026, 3:41:31 AM
 * Link: https://leetcode.com/problems/sort-vowels-by-frequency/
 */

class Solution {
public:
    string sortVowels(string s) {
        unordered_map <int, int> freq;
        int n = s.size();
        vector<int> first(26, -1);
        for(int i = n - 1; i >= 0; i--){
            char c = s[i];
            if(c == 'a' || c == 'e' ||c == 'i' || c == 'o' || c == 'u'){
                freq[c]++;
                first[c - 'a'] = i;
            }
            
        }
        priority_queue<tuple<int, int, int>> maxH;
        for(auto i : freq){
            int f = i.second;
            int c = i.first;
            maxH.push({f, -first[c - 'a'], c});
        }
        int i = 0;
        while(!maxH.empty()){
            auto[f, _, nc] = maxH.top();
            maxH.pop();
            while(i < n && f > 0){
                char c = s[i];
                if(c == 'a' || c == 'e' ||c == 'i' || c == 'o' || c == 'u'){
                    s[i] = nc; 
                    f--;
                }
                i++;
            }
        }
     
        return s;
    }
};
