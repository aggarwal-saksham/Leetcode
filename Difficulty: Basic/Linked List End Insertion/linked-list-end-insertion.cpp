/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* newN = new Node(x);
        if(!head) return newN;
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newN;
        return head;
    }
};