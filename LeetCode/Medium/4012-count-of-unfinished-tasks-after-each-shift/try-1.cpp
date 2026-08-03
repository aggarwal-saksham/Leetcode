/*
 * Problem #4012: Count of Unfinished Tasks After Each Shift
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/2/2026, 3:50:05 PM
 * Link: https://leetcode.com/problems/count-of-unfinished-tasks-after-each-shift/
 */

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> prefix(n);
        long long curr = 0;
        for(int i = 0; i < n; i++){
            curr += tasks[i];
            prefix[i] = curr;
        }
        vector<int> ans;
        long long prev = 0;
        long long total = prefix[n - 1];
        int m = shifts.size();
        for(int i = 0; i < m; i++){
            if(prev >= total) prev = 0;
            prev += shifts[i];
            //cout << prev << endl;
            int ub = upper_bound(prefix.begin(), prefix.end(), prev) - prefix.begin();
            //cout << ub << endl;
            
            ans.push_back(n - ub);
        }
        return ans;
    }
};
