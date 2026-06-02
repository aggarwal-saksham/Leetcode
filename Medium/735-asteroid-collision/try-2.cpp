/*
 * Problem #735: Asteroid Collision
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2026, 1:53:44 AM
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
                if (ast > 0)
                {
                    st.push(ast);
                    
                }
                else{

                    while (!st.empty() && st.top() < abs(ast) && st.top() > 0)
                    {
                       st.pop();
                       
                    }
                    if(!st.empty() && st.top() == abs(ast)) {
                    
                        st.pop();
                    }
                
                    else if(st.empty() || st.top() < 0){                        
                        st.push(ast);
                    }
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
