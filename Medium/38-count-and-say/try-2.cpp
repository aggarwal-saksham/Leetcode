/*
 * Problem #38: Count and Say
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2025, 5:06:27 PM
 * Link: https://leetcode.com/problems/count-and-say/
 */

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string num = "1";
        while (n > 1) {

            string ans = "";
            int cnt = 1;
            for (int i = 1; i < num.length(); i++) {
                if (num[i] == num[i - 1]) {
                    cnt++;
                    continue;
                }
                ans += to_string(cnt);
                ans += num[i - 1];
                cnt = 1;
            }

            ans += to_string(cnt);
            ans += num[num.size() - 1];
            num = ans;
            n--;
        }

        return num;
    }
};
