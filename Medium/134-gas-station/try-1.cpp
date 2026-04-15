/*
 * Problem #134: Gas Station
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/9/2026, 11:38:59 PM
 * Link: https://leetcode.com/problems/gas-station/
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), total = 0, curr = 0, ans = 0;
        for(int i = 0; i < n; i++){
            curr += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if((curr) < 0){
                ans = i + 1;
                curr = 0;
            }
           

        }
        return (total >= 0) ? ans : -1;
        
    }
};
