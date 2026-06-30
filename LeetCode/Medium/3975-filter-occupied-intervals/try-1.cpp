/*
 * Problem #3975: Filter Occupied Intervals
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2026, 7:27:19 PM
 * Link: https://leetcode.com/problems/filter-occupied-intervals/
 */

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int fs, int fe) {
        //2,8  10,12  14,16
        int n = occupiedIntervals.size();
        vector<vector<int>> is;
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        for(auto &i  : occupiedIntervals){
            int s = i[0], e = i[1];
            if(is.empty() || s - 1 > is.back()[1]) is.push_back(i);
            else{
                auto last = is.back();
                is.pop_back();
                is.push_back({last[0], max(last[1], e)});
            }            
        }
        vector<vector<int>> ans;
        for(auto &i : is){
            int s = i[0], e = i[1];
            if(e < fs || s > fe) ans.push_back({s, e});
            else if(s < fs && e >= fs  && e < fe){
                int n = fs - 1;
                ans.push_back({s, n});
            }
            else if(s <= fs && e >= fe){
                if(s != fs) ans.push_back({s, fs - 1});
                if(e != fe) ans.push_back({fe + 1, e});
            }
            else if(s > fs && s <= fe && e > fe){
                ans.push_back({fe + 1, e});
            }
            

            
        }
        return ans;

        
    }
};
