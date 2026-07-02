class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        Node* temp = head;
        while(temp){
            if(temp->prev && temp->prev->data == temp->data){
                Node* toDelete = temp;
                if(temp->prev) temp->prev->next = temp->next;
                if(temp->next) temp->next->prev = temp->prev;
                temp = temp->next;
                toDelete->next = NULL;
                toDelete->prev = NULL;
                delete toDelete;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};