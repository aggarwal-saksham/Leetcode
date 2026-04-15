/*
 * Problem #621: Task Scheduler
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/24/2025, 3:25:28 PM
 * Link: https://leetcode.com/problems/task-scheduler/
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        if (n == 0)
            return tasks.size();
        unordered_map<char, int> mpp;
        for (char task : tasks) {
            mpp[task]++;
        }
        typedef pair<int, char> pic;
        priority_queue<pic> maxH;
        stack<pic> st;

        for (auto i : mpp) {
            maxH.push({i.second, i.first});
        }
        while (!maxH.empty()) {
            int x = n + 1;
            while (x > 0 && !maxH.empty()) {
                if (maxH.top().first - 1 != 0) {
                    st.push({maxH.top().first - 1, maxH.top().second});
                }
                maxH.pop();
                ans++;
                x--;
                
            }
            while (!st.empty()) {

                maxH.push(st.top());
                st.pop();
            }

            if (!maxH.empty()) {
                ans += x;
            }
        }

        return ans;
    }
};
