/*
 * Problem #85: Maximal Rectangle
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2026, 3:43:41 PM
 * Link: https://leetcode.com/problems/maximal-rectangle/
 */

class Solution
{
    public:
        vector<int> nseInd(vector<int> &arr)
        {
            int n = arr.size();
            vector<int> nse(n, n);
            stack<int> st;

            for (int i = n - 1; i >= 0; i--)
            {

                while (!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                if (!st.empty())
                    nse[i] = st.top();
                st.push(i);
            }
            return nse;
        }

    vector<int> pseInd(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nseI = nseInd(heights);
        vector<int> pseI = pseInd(heights);
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int area = heights[i] *(nseI[i] - pseI[i] - 1);
            ans = max(ans, area);
        }

        return ans;
    }

    int maximalRectangle(vector<vector < char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            int area = largestRectangleArea(height);
            ans = max(ans, area);
        }
        return ans;
    }
};
