/*
 * Problem #4008: Minimum Initial Strength to Defeat All Monsters
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/1/2026, 9:01:15 PM
 * Link: https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/
 */

class Solution {
public:
    bool possible(vector<int>& monsters, long long mid, vector<long long> &temp){
        long long cur = mid;
        for(int i = 0; i < (int)monsters.size(); i++){
            if(cur + temp[i] < monsters[i]) return false;
            cur -= monsters[i];
            if(cur < 0) cur = 0;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> temp(n, 0);
        for(auto &b : boosts){
            long long l = b[0], r = b[1], t = b[2];
            temp[r] += t;
            if(l > 0) temp[l - 1] -= t;
        }
        long long val = 0;
        for(int i = n - 1; i >= 0; i--){
            val += temp[i];
            temp[i] = val;
            
        }

        long long l = 0, h = accumulate(monsters.begin(), monsters.end(), 0LL);

        while(l < h){
            long long mid = l + (h - l) / 2;

            if(possible(monsters, mid, temp)){
                h = mid;
            }
            else l = mid + 1;
        }
        return l;
        
    }
};
