#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>> &g, vector<int> &vis, stack<int> &st) {
    vis[u] = 1;
    for (int v : g[u]) if (!vis[v]) dfs1(v, g, vis, st);
    st.push(u);
}

void dfs2(int u, vector<vector<int>> &gt, vector<int> &vis) {
    vis[u] = 1;
    cout << u << " ";
    for (int v : gt[u]) if (!vis[v]) dfs2(v, gt, vis);
}

int main() {
    int n = 5;
    vector<vector<int>> g(n), gt(n);
    g[0] = {2,3};
    g[1] = {0};
    g[2] = {1};
    g[3] = {4};
    for (int u = 0; u < n; u++)
        for (int v : g[u]) gt[v].push_back(u);

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) if (!vis[i]) dfs1(i, g, vis, st);

    fill(vis.begin(), vis.end(), 0);
    cout << "SCCs:\n";
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!vis[u]) {
            dfs2(u, gt, vis);
            cout << "\n";
        }
    }
}
