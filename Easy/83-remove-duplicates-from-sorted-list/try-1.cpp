/*
 * Problem #83: Remove Duplicates from Sorted List
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2025, 3:19:20 PM
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
        if(!head || !head->next) return head; 
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = temp;
        while(temp->next){
            ListNode* front = temp->next;
            if(front->val == temp->val) temp->next = front->next;
            else temp = temp->next;
        }
        return dummy->next;
        
    }
};
