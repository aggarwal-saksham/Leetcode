/*
 * Problem #3668: Restore Finishing Order
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/31/2025, 2:24:21 PM
 * Link: https://leetcode.com/problems/restore-finishing-order/
 */

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        set<int> st;
        for(int f : friends){
            st.insert(f);
        }
        for(int id : order){
            if(st.find(id) != st.end()){
                ans.push_back(id);
            }
        }
        return ans;
    }
};
