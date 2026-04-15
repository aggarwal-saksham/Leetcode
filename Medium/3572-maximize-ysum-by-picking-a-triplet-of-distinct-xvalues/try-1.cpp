/*
 * Problem #3572: Maximize Y‑Sum by Picking a Triplet of Distinct X‑Values
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/7/2025, 8:21:14 PM
 * Link: https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/
 */

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++){
            if(mpp.find(x[i]) != mpp.end()){
                mpp[x[i]] = max(mpp[x[i]], y[i]);
                
            }

            else{
                mpp[x[i]] = y[i];
            }
        }

        priority_queue<int, vector<int>, greater<int>> minH;

        for(auto it : mpp){
            minH.push(it.second);
            if(minH.size() > 3) minH.pop();
        }

        if(minH.size() < 3) return -1;

        int ans = 0;
        while(!minH.empty()){
            ans += minH.top();
            minH.pop();
        }
        return ans;
    }
};
