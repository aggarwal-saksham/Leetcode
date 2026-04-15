/*
 * Problem #1792: Maximum Average Pass Ratio
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/2/2025, 1:42:00 AM
 * Link: https://leetcode.com/problems/maximum-average-pass-ratio/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        typedef tuple<double,double,int,int> tp;
        priority_queue<tp> pq;

        for (int i = 0; i < classes.size(); i++) {
            double avg = (double)classes[i][0] / classes[i][1];
            double diff = (double)(classes[i][0] + 1) / (classes[i][1] + 1) - avg;
            pq.push({diff, avg, classes[i][0], classes[i][1]});
        }

        while (extraStudents) {
            auto [diff, avg, pass, total] = pq.top();
            pq.pop();
            pass++;
            total++;
            avg = (double)pass / total;
            diff = (double)(pass + 1) / (total + 1) - avg;
            pq.push({diff, avg, pass, total});
            extraStudents--;
        }

        double ans = 0;
        while (!pq.empty()) {
            auto [diff, avg, pass, total] = pq.top();
            pq.pop();
            ans += avg;
        }

        return ans / classes.size();
    }
};

