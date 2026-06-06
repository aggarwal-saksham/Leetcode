class Solution {
  public:
    void insert(stack<int> &st, int t){
        if(st.empty()){
            st.push(t);
            return;
        }
        
        int t2 = st.top();
        st.pop();
        
        insert(st, t);
        st.push(t2);
        
        
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.size() == 1) return;
        
        int t = st.top();
        st.pop();
        
        reverseStack(st);
        
        insert(st, t);
    }
};