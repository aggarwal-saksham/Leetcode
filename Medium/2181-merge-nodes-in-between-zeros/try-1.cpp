/*
 * Problem #2181: Merge Nodes in Between Zeros
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2025, 2:56:14 AM
 * Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        ListNode* temp = head->next;
        while(temp){
            int x = 0;
            while(temp->val != 0){
                x += temp->val;
                temp = temp->next;
                if(temp->val == 0) break;
            }
            ListNode* newN = new ListNode(x);
            tail->next = newN;
            tail = newN;
            temp = temp->next;
        }
        return ans->next;
    }
};
