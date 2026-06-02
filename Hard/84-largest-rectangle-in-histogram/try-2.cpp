/*
 * Problem #84: Largest Rectangle in Histogram
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2026, 3:30:16 PM
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
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

    int largestRectangleArea(vector<int> &heights) {
        vector<int> nseI = nseInd(heights);
        vector<int> pseI = pseInd(heights);
        int n = heights.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int area = heights[i] * (nseI[i] - pseI[i] - 1);
            cout << area << " ";
            ans = max(ans, area);
        }

        return ans;
    }
};
