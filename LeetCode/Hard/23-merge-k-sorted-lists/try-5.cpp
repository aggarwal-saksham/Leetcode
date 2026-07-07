/*
 * Problem #23: Merge k Sorted Lists
 * Difficulty: Hard
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 11:49:25 PM
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        int k = lists.size();        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < k; i++) {
            ListNode* head = lists[i];
            if (head)
                pq.push(head);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!pq.empty()) {
            auto h = pq.top();
            pq.pop();

            temp->next = h;
            temp = temp->next;
            
            if (h->next) {
                pq.push(h->next);
            }
        }

        return dummy->next;
    }
};
