class Solution {
  public:
    stack<Node*> st1, st2;

    void pushleft(Node* node, stack<Node*>& st) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    int next(stack<Node*>& st) {
        Node* temp = st.top();
        st.pop();
        pushleft(temp->right, st);
        return temp->data;
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;

        pushleft(root1, st1);
        pushleft(root2, st2);

        while (!st1.empty() && !st2.empty()) {
            if (st1.top()->data <= st2.top()->data)
                ans.push_back(next(st1));
            else
                ans.push_back(next(st2));
        }

        while (!st1.empty())
            ans.push_back(next(st1));

        while (!st2.empty())
            ans.push_back(next(st2));

        return ans;
    }
};