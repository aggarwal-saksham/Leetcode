/*
 * Problem #415: Add Strings
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/17/2024, 7:33:25 PM
 * Link: https://leetcode.com/problems/add-strings/
 */

class Solution
{
    public:
        string addStrings(string num1, string num2)
        {
            int n1 = num1.length();
            int n2 = num2.length();
            string ans = "";
            int i = n1 - 1;
            int j = n2 - 1;
            int carry = 0,num = 0;
            while (i >= 0 || j >= 0 || carry)
            {
                int digit1 = i >= 0 ? num1[i] - '0' : 0;
                int digit2 = j >= 0 ? num2[j] - '0' : 0;
                int num = digit1 + digit2 + carry;

                ans += (num % 10) + '0';
                carry = num/10;

                i--;
                j--;
            }
           
            reverse(ans.begin(), ans.end());
            return ans;
        }
};
