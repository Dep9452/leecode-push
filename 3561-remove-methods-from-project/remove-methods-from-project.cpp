class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);

        for (auto &e : invocations)
            g[e[0]].push_back(e[1]);

        vector<bool> vis(n, false);
        stack<int> st;
        st.push(k);
        vis[k] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    st.push(v);
                }
            }
        }

        for (auto &e : invocations) {
            if (!vis[e[0]] && vis[e[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};