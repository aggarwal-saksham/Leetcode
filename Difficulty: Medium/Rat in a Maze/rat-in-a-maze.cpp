class Solution {
  public:
    void backtrack(int r, int c, vector<string> &ans, string &path, vector<vector<int>> &vis, vector<vector<int>>& maze){
        int n = maze.size();
        if(r == n - 1 && c == n - 1){
            if(maze[r][c] == 1) ans.push_back(path);
            return;
        }
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        string drxn = "ULDR";
        
        vis[r][c] = 1;
        
        for(int k = 0; k < 4; k++){
            
            int nrow = r + delrow[k];
            int ncol = c + delcol[k];
            char p = drxn[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                maze[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    path.push_back(drxn[k]);
                    backtrack(nrow, ncol, ans, path, vis, maze);
                    path.pop_back();
                }
        }
        
        vis[r][c] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        // code here
        vector<string> ans;
        string path;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        if(maze[0][0] == 1){
            backtrack(0, 0, ans, path, vis, maze);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};