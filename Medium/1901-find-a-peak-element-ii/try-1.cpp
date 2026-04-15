/*
 * Problem #1901: Find a Peak Element II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/4/2024, 8:46:06 PM
 * Link: https://leetcode.com/problems/find-a-peak-element-ii/
 */

class Solution {
public:
    int max_index_in_row(vector<vector<int>>& mat,int m, int n, int col){
        int max_el = -1, index = -1;
        for(int i = 0; i < m; i++ ){
            if(mat[i][col] > max_el){
                max_el = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int max_row_index = max_index_in_row(mat,m,n,mid);
            int left = mid - 1 >= 0 ? mat[max_row_index][mid - 1] : -1;
            int right = mid + 1 < n ? mat[max_row_index][mid + 1] : -1;

            if(mat[max_row_index][mid] > left && mat[max_row_index][mid] > right)
            return {max_row_index,mid};

            else if(mat[max_row_index][mid] < right) low = mid + 1;
            else high = mid - 1;
            
        }
        return {-1,-1};

    }
};
