class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(i);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(mat[i][j] == 1) {
                    s.erase(i);
                } else {
                    s.erase(j);
                }
            }
        }

        if(s.empty()) {
            return -1;
        }
        

        int c = *s.begin();

        

        return c;
    }
};