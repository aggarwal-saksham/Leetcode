/*
 * Problem #3926: Count Valid Word Occurrences
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/20/2026, 1:29:29 AM
 * Link: https://leetcode.com/problems/count-valid-word-occurrences/
 */

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for(string c : chunks){
            s += c;
        }

        unordered_map<string, int> mpp;
        string word = "";
        for(int i= 0; i < s.size(); i++){
            if(isalpha(s[i])) word += s[i];
            else{
                if(s[i] != '-' && word != "" && word.back() != '-'){
                    mpp[word]++;
                    cout << word << " ";
                    word = "";
                }
                else if(s[i] != '-' && word != ""  && word.back() == '-'){
                    word.pop_back();
                        mpp[word]++;
                    word = "";
                }
                else{
                    if(word == "") continue;
                    else if(word != "" && word.back() == '-'){
                        word.pop_back();
                        mpp[word]++;
                        cout << word << " ";
                        word = "";
                    }
                    else word += s[i];
                }
            }
        }
        if(word != "" && word.back() == '-')  word.pop_back();
        mpp[word]++;
        vector<int> ans;
        for(string q : queries){
            ans.push_back(mpp[q]);
        }
        return ans;
    }
};
