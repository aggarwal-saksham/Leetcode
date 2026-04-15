/*
 * Problem #551: Student Attendance Record I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/4/2025, 11:09:48 PM
 * Link: https://leetcode.com/problems/student-attendance-record-i/
 */

class Solution
{
    public:
        bool checkRecord(string s)
        {
            int a = 0, l = 0;
            int n = s.length();
            if (n == 1) return true;
            if (n == 2 && s == "AA") return false;
            for (int i = 0; i < n - 2; i++)
            {
                if (s[i] == 'A') a++;
                if (a > 1) return false;
                if (s.substr(i, 3) == "LLL") return false;
            }
            if (a == 1 && (s[n - 1] == 'A' || s[n - 2] == 'A')) return false;
            if (s[n - 1] == 'A' && s[n - 2] == 'A') return false;
            return true;
        }
};
