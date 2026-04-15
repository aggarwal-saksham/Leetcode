/*
 * Problem #25: Reverse Nodes in k-Group
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2025, 11:59:59 PM
 * Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev2temp = dummy;
        ListNode* temp = head;

        int total = 0;
        ListNode* countNode = head;
        while (countNode) {
            total++;
            countNode = countNode->next;
        }

        int numGroups = total / k;

        for (int group = 0; group < numGroups; group++) {
            ListNode* curr = temp;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prev2temp->next = prev;
            prev2temp = temp;
            temp = curr;
        }

        prev2temp->next = temp;
        return dummy->next;
    }
};
