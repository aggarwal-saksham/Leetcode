/*
 * Problem #1079: Letter Tile Possibilities
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/17/2025, 1:10:51 PM
 * Link: https://leetcode.com/problems/letter-tile-possibilities/
 */

class Solution {
public:
    void helper(string &tiles, map<int, int> &mp, set<string> &st, string &perm){
        if(!perm.empty()){
            st.insert(perm);
        }
        for(int i = 0; i < tiles.size(); i++){
            if(mp[i] == 0){
                mp[i] = 1;
                perm.push_back(tiles[i]);
                helper(tiles, mp, st, perm);
                mp[i] = 0;
                perm.pop_back();
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        map<int,int> mp;
        int n = tiles.size();
        for(int i = 0; i < n; i++){
            mp[i] = 0;
        }
        set<string> st;
        string perm;
        helper(tiles, mp, st, perm);
        return st.size();
    }
};

