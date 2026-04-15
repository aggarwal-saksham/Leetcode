/*
 * Problem #3606: Coupon Code Validator
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/6/2025, 12:51:35 PM
 * Link: https://leetcode.com/problems/coupon-code-validator/
 */

class Solution {
public:
    bool isValid(string& code_i) {
        if(code_i == "") return false;
        for (char c : code_i) {
            if (!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        typedef pair<string, string> pss;
        priority_queue<pss, vector<pss>, greater<pss>> pq;

        for (int i = 0; i < n; i++) {
            if (isActive[i]) {
                if (businessLine[i] == "electronics" ||
                    businessLine[i] == "grocery" ||
                    businessLine[i] == "pharmacy" ||
                    businessLine[i] == "restaurant") {
                    if (isValid(code[i])) {
                        pq.push({businessLine[i], code[i]});
                    }
                }
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            string a = pq.top().second;
            ans.push_back(a);
            pq.pop();
        }

        return ans;
    }
};
