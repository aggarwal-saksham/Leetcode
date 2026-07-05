class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int  n= mat.size();
        int m = mat[0].size();
        int l = 1e9, h = 0;
        for(int i = 0; i < n; i++){
            l = min(l, mat[i][0]);
            h = max(h, mat[i][m - 1]);
        }
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
                
            }
            if(cnt <= (n * m) / 2) l= mid + 1;
            else h = mid - 1;
        }
        return l;
    }
};
