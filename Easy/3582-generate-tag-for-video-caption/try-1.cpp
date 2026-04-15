/*
 * Problem #3582: Generate Tag for Video Caption
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2025, 5:46:27 PM
 * Link: https://leetcode.com/problems/generate-tag-for-video-caption/
 */

class Solution {
public:
    string generateTag(string caption) {
        string ans = "";
        if(caption[0] != ' ') ans += tolower(caption[0]);
        for(int i = 1; i < caption.size(); i++){
            if(caption[i] != ' ' && caption[i - 1] == ' '){
                if(ans == "") 
                    ans += tolower(caption[i]);
                else
                    ans += toupper(caption[i]);
            }

            else if(caption[i] != ' ' && caption[i - 1] != ' '){
                ans += tolower(caption[i]);

            }
            
        }

        string pre = "#";
        pre += ans;
        if(pre.size() > 100){
            pre = pre.substr(0, 100);
        }

        return pre;
    }
};
