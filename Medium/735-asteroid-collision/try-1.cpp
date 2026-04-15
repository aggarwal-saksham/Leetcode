/*
 * Problem #735: Asteroid Collision
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/27/2025, 10:30:28 PM
 * Link: https://leetcode.com/problems/asteroid-collision/
 */

class Solution
{
    public:
        vector<int> asteroidCollision(vector<int> &asteroids)
        {
            stack<int> st;
            for (int ast: asteroids)
            {
                while (!st.empty() && ast < 0 && st.top() > 0)
                {
                    if (abs(ast) > st.top())
                    {
                        st.pop();
                    }
                    else if (abs(ast) == st.top())
                    {
                        st.pop();
                        ast = 0;
                    }
                    else
                    {
                        ast = 0;
                    }
                }

                if (ast != 0)
                {
                    st.push(ast);
                    
                }
            }

            vector<int> ans;
            while (!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
};
