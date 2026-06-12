

class Solution {
  public:
  Node* targetNode;
    void storeAncestors(Node* root, unordered_map<Node*,Node*> &ancestor, int &target){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* n = q.front();
            if(n->data == target) targetNode = n;
            q.pop();

            if(n->left){
                q.push(n->left);
                ancestor[n->left] = n;
            }
            if(n->right){
                q.push(n->right);
                ancestor[n->right] = n;
            }
        }
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> ancestor;
        storeAncestors(root, ancestor, target);
        
        
        unordered_map<Node*, bool> vis;

        queue<Node*> q;
        q.push(targetNode);
        vis[targetNode] = 1;

        int time = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                Node* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = 1;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = 1;
                }
                if(ancestor[curr] && !vis[ancestor[curr]]){
                    q.push(ancestor[curr]);
                    vis[ancestor[curr]] = 1;
                }
            }
            time++;
        }
        
        return time - 1;

    }
};