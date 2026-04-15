/*
 * Problem #19: Remove Nth Node From End of List
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/19/2024, 12:46:45 PM
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) return NULL;

            
            ListNode *temp = head;
            int length = 0;
            while (temp != NULL)
            {
                temp = temp->next;
                length++;
            }

            
            if (n == length) {
                temp = head;
                head = head->next;
                delete temp;
                return head;
            }

            
            temp = head;
            for (int i = 1; i < length - n; i++)
            {
                temp = temp->next;
            }

            
            ListNode *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;

            return head;
    }
};
