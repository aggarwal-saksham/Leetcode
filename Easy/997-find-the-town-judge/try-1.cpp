/*
 * Problem #997: Find the Town Judge
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/17/2026, 1:26:57 PM
 * Link: https://leetcode.com/problems/find-the-town-judge/
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, set<int>> adjList;
        for(auto t : trust){
            adjList[t[0]].insert(t[1]);
        }

        for(int i = 1; i <= n; i++){
            if(!adjList.count(i)){
                bool notFound = false;
                for(auto it : adjList){
                    if(it.second.find(i) == it.second.end()) notFound = true;
                }
                if(!notFound && adjList.size() == n - 1) return i;
            }
        }
        return -1;
    }
};
