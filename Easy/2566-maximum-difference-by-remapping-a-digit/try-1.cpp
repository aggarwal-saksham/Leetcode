/*
 * Problem #2566: Maximum Difference by Remapping a Digit
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/14/2025, 1:16:36 PM
 * Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
 */

class Solution {
public:
    int minMaxDifference(int num) {
        char d1;
        string maxi = to_string(num);
        for(int i = 0; i < maxi.length(); i++){
            if(maxi[i] == '9') continue;
            else{ 
                d1 = maxi[i];
                break;
            }
        }
        for(int i = 0; i < maxi.length(); i++){
            if(maxi[i] == d1){
                maxi[i] = '9';
            }
        }

        char d2;
        string mini = to_string(num);
        for(int i = 0; i < mini.length(); i++){
            if(mini[i] == '0') continue;
            else{ 
                d2 = mini[i];
                break;
            }
        }
        for(int i = 0; i < mini.length(); i++){
            if(mini[i] == d2){
                mini[i] = '0';
            }
        }

        int diff = stoi(maxi) - stoi(mini);
        return diff;
    }
};
