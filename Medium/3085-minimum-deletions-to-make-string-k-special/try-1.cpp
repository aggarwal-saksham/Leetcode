/*
 * Problem #3085: Minimum Deletions to Make String K-Special
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/21/2025, 4:35:09 PM
 * Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/
 */

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char c : word){
            freq[c - 'a']++;
        }
        int ans = word.size();
        for (int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;

            int deletions = 0;
            int base = freq[i];

            for (int j = 0; j < 26; j++) {
                if (freq[j] < base) {
                    deletions += freq[j]; // delete all
                } else if (freq[j] > base + k) {
                    deletions += freq[j] - (base + k); 
                }
            }
            ans = min(ans, deletions);
        }

        return ans; 
    }
};
