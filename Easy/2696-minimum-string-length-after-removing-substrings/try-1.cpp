/*
 * Problem #2696: Minimum String Length After Removing Substrings
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/7/2024, 6:57:51 PM
 * Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
 */

class Solution {
public:
    int minLength(string s) {
        int n1  = s.size();
        stack<char> st;
        
            for(int i = 0 ; i < n1; i++){
                if(st.empty()) st.push(s[i]);
                else if((s[i] == 'B' && st.top() == 'A')
                        ||s[i] == 'D' && st.top() == 'C') 
                        st.pop();
                else st.push(s[i]);
            }
        return st.size();
        
    }
};
