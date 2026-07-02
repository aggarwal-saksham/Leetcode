/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        vector<pair<int, int>> ans;
        while(temp != head && head->next != temp){
            if(head->data + temp->data == target){
                ans.push_back({head->data, temp->data});
                head = head->next;
                temp = temp->prev;
            }
            else if(head->data + temp->data > target){
                temp = temp->prev;
            }
            else{
                head = head->next;
                
            }
            
        }
        if(head->next == temp){
            if(head->data + temp->data == target)
                ans.push_back({head->data, temp->data});
        }
        return ans;
    }
};