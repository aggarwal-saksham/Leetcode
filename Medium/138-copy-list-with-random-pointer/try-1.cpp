/*
 * Problem #138: Copy List with Random Pointer
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2025, 7:45:42 PM
 * Link: https://leetcode.com/problems/copy-list-with-random-pointer/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mpp;
        while (temp != NULL) {
            Node* newN = new Node(temp->val);
            mpp[temp] = newN;
            temp = temp->next;
        }
        temp = head;

        while (temp) {

            Node* temp2 = mpp[temp];

            temp2->next = mpp[temp->next];

            temp2->random = mpp[temp->random];

            temp = temp->next;
        }
        return mpp[head];
    }
};
