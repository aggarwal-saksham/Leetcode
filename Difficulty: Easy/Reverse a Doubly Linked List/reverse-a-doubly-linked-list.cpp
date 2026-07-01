/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
       Node* end = head;
       Node* start = head;
       int cnt = 0;
       while(end->next) {
           end = end->next;
           cnt++;
       }
       cnt++;
       int half = cnt / 2;
       while(half--){
           int x = start->data;
           start->data = end->data;
           end->data = x;
           
           start = start->next;
           end = end->prev;
       }
       return head;
    }
};