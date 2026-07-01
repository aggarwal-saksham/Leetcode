/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int cnt = 1;
        Node* temp = head;
        if(head == NULL) return 0;
        while(temp->next != NULL){
            temp = temp->next;
            cnt++;
            
            
        }
        return cnt;
        // Code here
    }
};

