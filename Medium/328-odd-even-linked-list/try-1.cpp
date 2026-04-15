/*
 * Problem #328: Odd Even Linked List
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/19/2024, 12:25:21 PM
 * Link: https://leetcode.com/problems/odd-even-linked-list/
 */

    /**
     *Definition for singly-linked list.
     *struct ListNode {
     *   int val;
     *   ListNode * next;
     *   ListNode() : val(0), next(nullptr) {}
     *   ListNode(int x) : val(x), next(nullptr) {}
     *   ListNode(int x, ListNode *next) : val(x), next(next) {}
     *};
     */
    class Solution
    {
        public:
            ListNode* oddEvenList(ListNode *head)
            {
                if (head == NULL) return NULL;
                if (head->next == NULL || head->next->next == NULL)
                    return head;
                ListNode *odd = head;
                ListNode *even = head->next;
                ListNode *evenHead = head->next;
               
                while (even != NULL && even->next != NULL){
                    odd->next = odd->next->next;
                
                    even->next = even->next->next;
                    odd = odd->next;
                    even = even->next;
                }
                odd->next = evenHead;
                return head;
            }
    };
