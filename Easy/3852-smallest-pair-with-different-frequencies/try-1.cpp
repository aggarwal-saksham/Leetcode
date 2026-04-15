/*
 * Problem #3852: Smallest Pair With Different Frequencies
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/28/2026, 8:07:45 PM
 * Link: https://leetcode.com/problems/smallest-pair-with-different-frequencies/
 */

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii> , greater<pii>> minH;
        for(auto it : freq){
            minH.push({it.first, it.second});
        }
        vector<int> ans;

        ans.push_back(minH.top().first);
        int f = minH.top().second;
        minH.pop();
        while(!minH.empty()){
            if(minH.top().second != f){
                ans.push_back(minH.top().first);
                return ans;
            }
            minH.pop();
            
        }

        return {-1, -1};

        
    }
};
