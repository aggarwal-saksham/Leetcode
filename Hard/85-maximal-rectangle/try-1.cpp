/*
 * Problem #85: Maximal Rectangle
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/29/2025, 7:55:50 PM
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
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            int colMax = largestRectangleArea(heights);
            ans = max(ans, colMax);
        }

        return ans;
    }
};
