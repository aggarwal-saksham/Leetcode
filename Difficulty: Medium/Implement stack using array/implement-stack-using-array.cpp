class myStack {
  public:
    vector<int> st;
    int top = -1;
    int n;
    myStack(int n) {
        // Define Data Structures
        this->n = n;
        st.resize(n);
    }

    bool isEmpty() {
        // check if the stack is empty
        return (top == -1);
    }

    bool isFull() {
        // check if the stack is full
        return (top + 1 == n);
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(top + 1 >= n) return;
        top++;
        st[top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(top > -1) top--;
        else return;
    }

    int peek() {
        // Returns the top element of the stack
        if(top > -1) return st[top];
        else return -1;
    }
};