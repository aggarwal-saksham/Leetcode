/*
 * Problem #23: Merge k Sorted Lists
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/26/2025, 2:25:34 AM
 * Link: https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (!head1 && !head2)
            return NULL;
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        while(t1 && t2){
            if(t1->val < t2->val){
                temp->next = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }

            temp = temp->next;
        }

        if(t1){
            temp->next = t1;            
        }
        if(t2){
            temp->next = t2;           
        }
        
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        if(n == 1) return lists[0];
        ListNode* ans = mergeTwoLists(lists[0], lists[1]);

        for(int i = 2; i < n; i++){
            ans = mergeTwoLists(ans, lists[i]);
        }

        return ans;
    }
};
