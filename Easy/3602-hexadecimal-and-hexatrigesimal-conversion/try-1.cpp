/*
 * Problem #3602: Hexadecimal and Hexatrigesimal Conversion
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 8:45:30 PM
 * Link: https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/
 */

class Solution {
public:
    string concatHex36(int n) {
        string hexaD = "";
        long long nsq = 1LL * n * n;
        
        while(nsq > 0){
            int x = nsq % 16;
            if(x > 9) hexaD += 'A' + (x - 10);
            else hexaD += '0' + x;

            nsq = nsq / 16;
            
        }

        if(hexaD == "") hexaD += '0';
        reverse(hexaD.begin(), hexaD.end());
        
        string hexaT = "";
        long long ncube = 1LL * n * n * n;
        
        while(ncube > 0){
            int x = ncube % 36;
            if(x > 9) hexaT += 'A' + (x - 10);
            else hexaT += '0' + x;

            ncube = ncube / 36;
            
        }

        if(hexaT == "") hexaT += '0';
        reverse(hexaT.begin(), hexaT.end());
        return hexaD + hexaT;
    }
};
