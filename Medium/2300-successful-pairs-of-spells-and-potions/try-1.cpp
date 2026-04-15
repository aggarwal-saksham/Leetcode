/*
 * Problem #2300: Successful Pairs of Spells and Potions
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/11/2025, 7:18:51 PM
 * Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
 */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int n = potions.size();
        for(int s : spells){
            int l = 0;
            int h = n - 1;
            while(l <= h){
                int m = l + (h - l)/2;
                long long product = (long long)s * (long long)potions[m];
                if(product >= success){
                    h = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
            ans.push_back(n - l);
        }
        return ans;

    }
};
