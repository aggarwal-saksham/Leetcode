class Solution {
  public:
    bool create(vector<string> &words, vector<vector<int>> &adj,
                vector<int> &indeg, vector<bool> &present) {
        int n = words.size();

        for (string &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];

            int len = min(w1.length(), w2.length());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';

                    adj[u].push_back(v);
                    indeg[v]++;
                    found = true;
                    break;
                }
            }

            if (!found && w1.length() > w2.length()) {
                return false;
            }
        }

        return true;
    }

    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        vector<bool> present(26, false);

        if (!create(words, adj, indeg, present))
            return "";

        queue<int> q;
        string ans = "";

        for (int i = 0; i < 26; i++) {
            if (present[i] && indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans.push_back(u + 'a');

            for (int v : adj[u]) {
                indeg[v]--;

                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (present[i] && indeg[i] > 0)
                return "";
        }

        return ans;
    }
};