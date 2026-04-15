/*
 * Problem #2104: Sum of Subarray Ranges
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/26/2025, 6:05:30 PM
 * Link: https://leetcode.com/problems/sum-of-subarray-ranges/
 */

class Solution {
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

    vector<int> ngeInd(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                nge[i] = st.top();
            }

            st.push(i);
        }

        return nge;
    }

    vector<int> pseInd(vector<int> &arr)
    {
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

    vector<int> pgeInd(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                pge[i] = st.top();
            }

            st.push(i);
        }

        return pge;
    }

    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        vector<int> nseI = nseInd(arr);
        vector<int> pseI = pseInd(arr);

        for (int i = 0; i < n; i++)
        {
            ans += (long long)arr[i] * (nseI[i] - i) * (i - pseI[i]);
        }

        return ans;
    }

    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        vector<int> ngeI = ngeInd(arr);
        vector<int> pgeI = pgeInd(arr);

        for (int i = 0; i < n; i++)
        {
            ans += (long long)arr[i] * (ngeI[i] - i) * (i - pgeI[i]);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& arr) {
        return sumSubarrayMaxs(arr) - sumSubarrayMins(arr);
    }
};

