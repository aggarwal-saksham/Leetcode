/*
 * Problem #3838: Weighted Word Mapping
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/14/2026, 8:10:35 PM
 * Link: https://leetcode.com/problems/weighted-word-mapping/
 */

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            int m = words[i].length();
            int wt = 0;
            for(int j = 0; j < m; j++ ){
                
                wt = (wt + weights[(words[i][j] - 'a')]) % 26;
            }
            ans += 'a' + (26 - wt - 1);
        }
        return ans;
    }
};
