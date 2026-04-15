/*
 * Problem #82: Remove Duplicates from Sorted List II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2025, 4:05:27 PM
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp1 = dummy;
        ListNode* temp2 = temp1->next;
        while (temp2 && temp2->next) {
            if (temp2->next->val == temp2->val) {

                while (temp2->next && temp2->next->val == temp2->val) {
                    temp2 = temp2->next;
                }
                temp1->next = temp2->next;
            }

            else
                temp1 = temp2;
            temp2 = temp2->next;
        }

        return dummy->next;
    }
};
