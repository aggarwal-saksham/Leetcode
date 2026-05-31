/* Structure of linked list Node
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
class myStack {

  public:
    Node* top;
    int sz = 0;
    myStack() {
        // Initialize your data members
        top = NULL;
    }

    bool isEmpty() {
        // check if the stack is empty
        return sz == 0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        
        Node* newN = new Node(x);

        newN->next = top;
        top = newN;
        sz++;
        
    }

    void pop() {
        // Removes the top element of the stack
        if(sz == 0) return;
        Node* temp = top;
        top = top->next;
        delete(temp);
        sz--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(sz == 0) return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return sz;
    }
};