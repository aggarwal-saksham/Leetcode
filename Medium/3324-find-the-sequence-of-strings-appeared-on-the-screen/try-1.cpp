/*
 * Problem #3324: Find the Sequence of Strings Appeared on the Screen
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/20/2024, 8:12:12 PM
 * Link: https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/
 */

class Solution {
public:
    vector<string> stringSequence(string target) {

       vector<string> ans;
       string s = "";
       for(char c : target){
            s += 'a';
            ans.push_back(s);

            while(s.back() != c){
                if(s.back() == 'z') s.back() = 'a';
                else s.back() += 1;
                ans.push_back(s);
            }
       }
       return ans;
    }
};
