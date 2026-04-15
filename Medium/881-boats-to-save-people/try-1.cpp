/*
 * Problem #881: Boats to Save People
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/19/2026, 4:40:46 PM
 * Link: https://leetcode.com/problems/boats-to-save-people/
 */

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n - 1;
        int boats = 0;
        while(l <= r){
            if(people[l] + people[r] <= limit){
                l++;
            }
            r--;
            boats++;
        }
        return boats;
    }
};
