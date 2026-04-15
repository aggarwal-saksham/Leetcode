/*
 * Problem #143: Reorder List
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/12/2024, 8:20:11 PM
 * Link: https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow;
        ListNode* end = fast;
        ListNode* next2mid = slow->next;
        slow->next = nullptr;

        ListNode* temp = next2mid;
        ListNode* prev = NULL;
        ListNode* front = NULL;
//1>2>3>4<5<6<7
//1 7 2 6 3 5 4    
        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;

        }
        end = prev;
        temp = head;
        ListNode* tempend = NULL;
        while(temp != NULL && end != NULL){
            front = temp->next;
            tempend = end->next;
            temp->next = end;
            end->next = front;
            temp = front;
            end = tempend;
        }
    
        
    }
};
