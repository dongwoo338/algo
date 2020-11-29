#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 5005;
bool vis[N];
vector<vector<int>>g;
vector<vector<int>>ng;
stack<int>st;
void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v])dfs(v);
    }
    st.push(u);
}
int dfs2(int u) {
    int ret = 1;
    vis[u] = 0;
    for (int v : ng[u]) {
        if(vis[v])ret += dfs2(v);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    ng.resize(n + 1);
    for (int u, v; m--;) {
        cin >> u >> v;
        g[u].push_back(v);
        ng[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])dfs(i);
    }
    int ans = 0;
    while (st.size()) {
        int u = st.top(); st.pop();
        if (vis[u])ans = max(ans, dfs2(u));
    }
    cout << ans;
}