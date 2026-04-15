/*
 * Problem #92: Reverse Linked List II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/29/2024, 1:00:48 PM
 * Link: https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        if(left == right) return head;

        if (left == 1) {
            ListNode* prev = nullptr;
            ListNode* current = head;
            for (int i = 1; i <= right; ++i) {
                ListNode* nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }
            head->next = current; 
            return prev;          
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int cnt1 = 1;
        int cnt2 = 1;
        while(cnt1  < left - 1){
            temp1 = temp1->next;
            cnt1++;
        }
        ListNode* preLeft = temp1;
        temp1 = temp1->next;
        ListNode* leftNode = temp1;
        
        while(cnt2  < right){
            temp2 = temp2->next;
            cnt2++;
        }
        ListNode* rightNode = temp2;
        ListNode* postRight = temp2->next;

        
        ListNode* prev = postRight;
        ListNode* front = NULL;
        while(temp1 != postRight){
            front = temp1->next;
            temp1->next = prev;
            prev = temp1;
            temp1 = front;
       
        }
        preLeft->next = rightNode;
        leftNode->next = postRight;

        return head;
    }
};
