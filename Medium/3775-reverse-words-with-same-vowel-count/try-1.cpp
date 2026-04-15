/*
 * Problem #3775: Reverse Words With Same Vowel Count
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/19/2025, 12:53:10 AM
 * Link: https://leetcode.com/problems/reverse-words-with-same-vowel-count/
 */

class Solution
{
public:
    bool isVowel(char &c)
    {
        return (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u');
    }

    string reverseWords(string s)
    {
        int l = 0, vowels = 0;
        string firstWord = "";
        int n = s.size();

        while (l < n && s[l] != ' ')
        {
            if (isVowel(s[l]))
                vowels++;
            firstWord += s[l];
            l++;
        }
        l++;

        string ans = firstWord;
        string word = "";
        int cnt = 0;

        while (l < n)
        {

            if (s[l] == ' ')
            {
                if (cnt == vowels)
                {
                    reverse(word.begin(), word.end());
                }
                ans += " " + word;
                word = "";
                cnt = 0;
            }
            else {
                word += s[l];
                if (isVowel(s[l]))
                    cnt++;
            }
            l++;
        }
        if (cnt == vowels)
            {
                reverse(word.begin(), word.end());
            }
        if(word != "") ans += " "  + word;


        return ans;
    }
};

