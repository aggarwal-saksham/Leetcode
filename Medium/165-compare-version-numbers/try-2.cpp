/*
 * Problem #165: Compare Version Numbers
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2025, 1:02:59 AM
 * Link: https://leetcode.com/problems/compare-version-numbers/
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1; 
        vector<int> v2;
        int i = 0;
        while(i < version1.length()){
            string part = "";
            
            while(i < version1.length() && version1[i] != '.') {
                part += version1[i];
                i++;
            }
            cout << stoi(part) << endl;
            if(!part.empty()) v1.push_back(stoi(part));

            i++;
        } 

        i = 0;
        while(i < version2.length()){
            string part = "";
            
            while(i < version2.length() && version2[i] != '.') {
                part += version2[i];
                i++;
            }
            cout << stoi(part) << endl;
            if(!part.empty()) v2.push_back(stoi(part));

            i++;
        } 

        int mini = min(v1.size(), v2.size());
        
        i = 0;
        for(i = 0; i < mini; i++){
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
        }

        while(i < v1.size()){
            if(v1[i] != 0) return 1;
            i++;
        }

        while(i < v2.size()){
            if(v2[i] != 0) return -1;
            i++;
        }

        return 0;
    }
};
