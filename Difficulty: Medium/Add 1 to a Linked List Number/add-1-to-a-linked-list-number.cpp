/* Structure of linked  Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head) {
        if(!head || !head->next) return head;
        Node* node = head;
        Node* back = NULL;
        while(node){
            Node* front = node->next;
            node->next = back;
            back = node;
            node = front;
        }
        return back;
    }
    Node* addOne(Node* head) {
        // code here
        Node* temp = reverse(head);
        Node* n = temp;
        int rem = 0;
        n->data++;
        rem += n->data / 10;
        n->data %= 10;
        Node* prev = n;
        n = n->next;
        
        while(n && rem > 0){
            n->data += rem;
            rem--;
            rem += n->data / 10;
            n->data %= 10;
            prev = n;
            n = n->next;
        }
        if(rem){
            Node* newN = new Node(1);
            prev->next = newN;
        }
        
        return reverse(temp);
        
    }
};