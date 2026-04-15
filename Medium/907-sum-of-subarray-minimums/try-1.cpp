/*
 * Problem #907: Sum of Subarray Minimums
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/26/2025, 4:19:53 PM
 * Link: https://leetcode.com/problems/sum-of-subarray-minimums/
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
                {
                    nse[i] = st.top();
                }

                st.push(i);
            }

            return nse;
        }

    vector<int> pseInd(vector<int> &arr)
    {
       	//prev smaller or equal
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();

        long long ans = 0, mod = 1e9 + 7;
        vector<int> nseI = nseInd(arr);
        vector<int> pseI = pseInd(arr);

        for (int i = 0; i < n; i++)
        {
            ans = (ans + (long long)arr[i] * (nseI[i] - i) % mod * (i - pseI[i]) % mod) % mod;
        }

        return (int) ans;
    }
};
