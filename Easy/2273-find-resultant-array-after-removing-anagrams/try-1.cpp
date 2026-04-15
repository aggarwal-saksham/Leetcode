/*
 * Problem #2273: Find Resultant Array After Removing Anagrams
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/13/2025, 8:16:48 PM
 * Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
 */

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        vector<string> copy = words;
        for(string &word : copy){
            sort(word.begin(), word.end());
        }
        ans.push_back(words[0]);
        for(int i = 1; i < n; i++){
            if(copy[i] == copy[i - 1]){
                continue;
            }
            else{
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
