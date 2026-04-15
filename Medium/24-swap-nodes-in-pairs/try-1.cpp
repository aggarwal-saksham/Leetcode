/*
 * Problem #24: Swap Nodes in Pairs
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/17/2025, 8:52:03 PM
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapPairs(ListNode *head)
        {
            if (!head || !head->next) return head;
            
            ListNode *dummy = new ListNode(-1);
            ListNode *prev2head = new ListNode(-1);
            ListNode *temp = head;
            prev2head->next = head;
            ListNode *prev2temp = prev2head;
            dummy->next = head->next;
            
            while (temp && temp->next)
            {
                ListNode *front = temp->next;
                temp->next = front->next;
                front->next = temp;
                prev2temp->next = front;
            
                prev2temp = temp;
                temp = temp->next;
            }

            return dummy->next;
        }
};
