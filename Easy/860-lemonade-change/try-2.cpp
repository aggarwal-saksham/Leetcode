/*
 * Problem #860: Lemonade Change
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 12/31/2024, 4:51:25 PM
 * Link: https://leetcode.com/problems/lemonade-change/
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                fives += 1;
            }
            else if(bills[i] == 10){
                tens += 1;
                if(!fives) return false;
                fives -= 1;
            }
            else{
                if((!tens && !fives) ||
                    tens && !fives) return false;
                if(tens && fives) {
                    tens -= 1;
                    fives -= 1;
                    //continue;
                }
                else if(!tens && fives >= 3){
                    fives -= 3;
                }
                else return false;

            } 
        }
        return true;
    }
};
