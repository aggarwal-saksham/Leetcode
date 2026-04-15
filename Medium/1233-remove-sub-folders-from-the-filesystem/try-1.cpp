/*
 * Problem #1233: Remove Sub-Folders from the Filesystem
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/20/2025, 1:48:21 PM
 * Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
 */

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st;
        sort(folder.begin() , folder.end());
        for(int i = 0; i < folder.size(); i++){
            string fldr = folder[i]; 
            int j = 1;
            string sub = "";
            while(j < fldr.size()){
                sub += '/';
                while(fldr[j] != '/' && j < fldr.size()){
                    sub += fldr[j];
                    j++;
                }
                if(st.find(sub) != st.end()) break;
                j++;
            }
            st.insert(sub);
        }

        vector<string> ans;
        for(auto str : st){
            ans.push_back(str);
        }

        return ans;
    }
};
