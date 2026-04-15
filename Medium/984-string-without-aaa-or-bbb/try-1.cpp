/*
 * Problem #984: String Without AAA or BBB
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/2/2025, 11:40:13 PM
 * Link: https://leetcode.com/problems/string-without-aaa-or-bbb/
 */

class Solution
{
    public:
        string strWithout3a3b(int a, int b)
        {
            string ans = "";
            while (a || b)
            {
                if (a > b && (ans.size() < 2 || ans.substr(ans.length() - 2) != "aa"))
                {
                    ans += 'a';
                    a--;
                }
                else if (a > b && (ans.size() < 2 || ans.substr(ans.length() - 2) == "aa"))
                {
                    ans += 'b';
                    b--;
                }
                else if (a == b && (ans.size() < 2 || ans.substr(ans.length() - 1) == "a") )
                {
                    ans += "ba";
                    a--;
                    b--;
                }
                else if (a == b && (ans.size() < 2 || ans.substr(ans.length() - 1) == "b") )
                {
                    ans += "ab";
                    a--;
                    b--;
                }
                else if (a < b && (ans.size() < 2 || ans.substr(ans.length() - 2) != "bb"))
                {
                    ans += 'b';
                    b--;
                }
                else if (a < b && (ans.size() < 2 || ans.substr(ans.length() - 2) == "bb"))
                {
                    ans += 'a';
                    a--;
                }
            }
            return ans;
        }
};
