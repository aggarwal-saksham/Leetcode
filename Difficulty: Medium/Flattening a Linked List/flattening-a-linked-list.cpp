
class Solution {
  public:
    Node* mergeTwoLists(Node* head1, Node* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        if (!head1 && !head2)
            return NULL;

        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (head1 && head2) {
            if (head1->data < head2->data) {
                temp->bottom = head1;
                head1 = head1->bottom;
            } 
            else {
                temp->bottom = head2;
                head2 = head2->bottom;
            }
            temp = temp->bottom;
        }
        if (head1)
            temp->bottom = head1;
        else
            temp->bottom = head2;

        return dummy->bottom;
    }

    Node* middleNode(Node* head) {
        Node* fast = head->bottom;
        Node* slow = head;

        while (fast && fast->bottom) {
            slow = slow->bottom;
            fast = fast->bottom->bottom;
        }
        return slow;
    }
    
    Node* sortList(Node* head) {
        if (!head || !head->bottom)
            return head;

        Node* middle = middleNode(head);
        Node* rightHead = middle->bottom;
        middle->bottom = NULL;
        Node* leftHead = head;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeTwoLists(leftHead, rightHead);
    }
    
    Node *flatten(Node *head) {
        // code here
        Node* t = head;
        Node* f = head->bottom;
        Node* dummy = new Node(-1);
        Node* d = dummy;
        
        while(t){
            Node* b = t;
            while(b){
                Node* n = new Node(b->data);
                d->bottom = n;
                b = b->bottom;
                d = d->bottom;
                
            }
            t = t->next;
        }
        return sortList(dummy->bottom);
    }
};