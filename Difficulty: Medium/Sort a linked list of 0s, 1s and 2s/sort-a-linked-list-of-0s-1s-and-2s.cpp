/* Node is defined as
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
    Node* segregate(Node* head) {
        // code here
        Node* temp = head;
        Node* zero = NULL;
        Node* one = NULL;
        Node* two = NULL;
        while(temp){
            if(temp->data == 0 && !zero) zero = temp;
            else if(temp->data == 1 && !one) one = temp;
            else if(temp->data == 2 && !two) two = temp;
            temp = temp->next;
        }
        
        Node* zeroH = zero;
        Node* oneH = one;
        Node* twoH = two;
        
        while(head){
            if(head->data == 0 && head != zero){
                zero->next = head;
                zero = zero->next;
            }
            else if(head->data == 1 && head != one){
                one->next = head;
                one = one->next;
            }
            else if(head->data == 2 && head != two){
                two->next = head;
                two = two->next;
            }
            head = head->next;
            
        }
        if(zero) zero->next = oneH ? oneH : twoH;
        if(one) one->next = twoH;
        if(two) two->next = NULL;
        
        if(zeroH) return zeroH;
        if(oneH) return oneH;
        return twoH;
    }
};