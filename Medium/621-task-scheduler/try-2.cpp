/*
 * Problem #621: Task Scheduler
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/29/2026, 12:56:05 AM
 * Link: https://leetcode.com/problems/task-scheduler/
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        unordered_map<char, int> freq;
        for(char t : tasks){
            freq[t]++;
        }
        priority_queue<int> maxH;
        for(auto it : freq){
            maxH.push(it.second);
        }


        while(!maxH.empty()){

            stack<int> st;
            int cycle = n + 1;

            while(cycle > 0 && !maxH.empty()){
                int cnt = maxH.top();
                maxH.pop();

                cnt--;
                if(cnt > 0) st.push(cnt);

                cycle--;

                ans++;
            }

            while(!st.empty()){
                int x = st.top();
                st.pop();
                maxH.push(x);
            }

            if(!maxH.empty()){
                ans += cycle;
            }

        }
        return ans;
    }
};
