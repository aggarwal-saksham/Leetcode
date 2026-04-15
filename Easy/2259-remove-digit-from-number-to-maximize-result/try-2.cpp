/*
 * Problem #2259: Remove Digit From Number to Maximize Result
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 10/5/2024, 1:15:12 AM
 * Link: https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
 */

class Solution {
public:
    string removeDigit(string number, char digit) {
        string maxi = "";
        for(int i = 0; i < number.size(); i++){
            string copy = number;
            if(number[i] == digit){
            string result = copy.substr(0,i) + 
                    copy.substr(i+1, number.length());
            maxi = max(maxi,result);
            }

        }
        return maxi;
        
    }
};
