/*
 * Problem #680: Valid Palindrome II
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/11/2024, 12:46:52 AM
 * Link: https://leetcode.com/problems/valid-palindrome-ii/
 */

class Solution {
public:
    bool validPalindrome(string s) {
        //deddde
        //ebcbb e cecabbacec bbcbe
        //ebcbbcecabbacecbbcbe
        //ababaab
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(s[left] != s[right]){
                int l1 = left + 1, r1 = right;
                int l2 = left, r2 = right - 1;

                while(l1 < r1  && s[l1] == s[r1]){
                    
                    l1++;
                    r1--;
                }
                while(l2 < r2  && s[l2] == s[r2]){
                    l2++;
                    r2--;
                }
                return l1 >= r1  || l2 >= r2;


            }

            else{
                left++;
                right--;
            }
        }
        return true;
    }
};
