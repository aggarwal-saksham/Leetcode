/*
 * Problem #1054: Distant Barcodes
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/17/2025, 1:49:32 AM
 * Link: https://leetcode.com/problems/distant-barcodes/
 */

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.size() == 1 || barcodes.size() == 0)
            return barcodes;
        unordered_map<int, int> freq;
        for (int num : barcodes) {
            freq[num]++;
        }
        priority_queue<pair<int, int>> maxH;
        for (auto it : freq) {
            maxH.push({it.second, it.first});
        }
        vector<int> ans;
        while (maxH.top().first != 0) {
            pair<int, int> x = maxH.top();
            maxH.pop();
            ans.push_back(x.second);
            x.first--;
            pair<int, int> y = maxH.top();
            maxH.pop();
            if (y.first > 0) {
                ans.push_back(y.second);
                y.first--;
            }

            maxH.push(y);
            maxH.push(x);
        }
        return ans;
    }
};
