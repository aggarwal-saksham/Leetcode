/*
 * Problem #2058: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2025, 2:20:09 PM
 * Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        int ind = 0;
        vector<int> pts;
        while (temp->next->next) {
            if ((temp->next->val > temp->val && temp->next->val > temp->next->next->val) ||
                (temp->next->val < temp->val && temp->next->val < temp->next->next->val)) {
                pts.push_back(ind);
            }
            ind++;
            temp = temp->next;
        }

        vector<int> ans;
        int n = pts.size();
        if (n < 2) return {-1, -1}; 

        int mini = INT_MAX;
        for (int i = 1; i < n; i++) {
            // cout << pts[i];
            mini = min(mini, pts[i] - pts[i - 1]);
        }
        ans.push_back(mini);
        ans.push_back(pts[n - 1] - pts[0]);
        return ans;
    }
};
