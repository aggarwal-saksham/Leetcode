class Solution {
  public:
    void fun(int ind,vector<int>&arr,vector<int>&inorder)
    {
        if(ind>=arr.size()) return ;
        
        fun(2*ind+1,arr,inorder);
        inorder.push_back(arr[ind]);
        fun(2*ind+2,arr,inorder);
    }
    
    int minSwaps(vector<int>& arr) {
        // Write your code here
        //8 6 9 5 10 7 11
        // 5 6 7 8 9 10 11
        //ceil(5 / 2)
        
        
        //1 4 3 5 2 6 7 
        //5 4 2 1 6 3 7
        //1 2 3 4 5 6 7
        // 9 : 8
        // 10 : 9
        // 7 : 7//
        // 8 : 10
        int n = arr.size();
        vector<int> inorder;
        fun(0, arr, inorder);
        sort(arr.begin(), arr.end());
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
            v.push_back({inorder[i], i});
        
        sort(v.begin(), v.end());
        
        vector<int> vis(n, 0);
        int swaps = 0;
        
        for(int i = 0; i < n; i++){
            if(vis[i] || v[i].second == i)
                continue;
        
            int cnt = 0;
            int j = i;
        
            while(!vis[j]){
                vis[j] = 1;
                j = v[j].second;
                cnt++;
            }
        
            swaps += cnt - 1;
        }
        
        return swaps;
    }
};