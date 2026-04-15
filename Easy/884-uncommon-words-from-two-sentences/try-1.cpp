/*
 * Problem #884: Uncommon Words from Two Sentences
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/17/2024, 12:02:07 PM
 * Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/
 */

class Solution
{
    public:
        vector<string> uncommonFromSentences(string s1, string s2)
        {
            vector<string> ans;
            unordered_map<string, int> mp;
            for (int i = 0; i < s1.size(); i++)
            {
                string word;
                if (s1[i] == ' ') continue;
                while (i < s1.size() && s1[i] != ' ')
                {
                    word += s1[i];
                    i++;
                }
                mp[word]++;
            }
            for (int i = 0; i < s2.size(); i++)
            {
                string word;
                if (s2[i] == ' ') continue;
                while (i < s2.size() && s2[i] != ' ')
                {
                    word += s2[i];
                    i++;
                }
                mp[word]++;
            }
            for(auto i : mp)
            if(i.second == 1) ans.push_back(i.first);

            return ans;
        }
};
