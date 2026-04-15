/*
 * Problem #3597: Partition String 
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2025, 2:02:43 PM
 * Link: https://leetcode.com/problems/partition-string/
 */

class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        set<string> st;
        string a = "";
        for(char c : s){
            a += c;
            if(st.find(a) == st.end()){
                ans.push_back(a);
                st.insert(a);
                a = "";
            }
        }

        return ans;
    }
};
