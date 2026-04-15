/*
 * Problem #3304: Find the K-th Character in String Game I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2025, 12:25:36 PM
 * Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
 */

class Solution {
public:
    char kthCharacter(int k) {
        string base  = "a";
        string curr = "";
        while(base.length() <= k){
            for(int i = 0; i < base.length(); i++){
                if(base[i] == 'z'){
                    curr += 'a';
                }
                else curr += (base[i] - 'a') + 1 + 'a';
            }
            
            base += curr;
            curr = "";

            if(base.length() > k){                
                return base[k - 1];
            }
                
        }


        return base[k - 1];
    }
};
