/*
 * Problem #3024: Type of Triangle
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/22/2025, 6:31:19 PM
 * Link: https://leetcode.com/problems/type-of-triangle/
 */

class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool isTriangle = false;

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if((a + b > c) && (b + c > a) && (c + a > b)){
            isTriangle = true;
        }

        if(!isTriangle) return "none";
        else{
            if(a==b && b==c && c==a) return "equilateral";
            else if (a==b || b==c || c==a) return "isosceles";
            else return "scalene";
        }

    }
};
