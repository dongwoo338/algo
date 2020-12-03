#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int t;
vector<vector<int>>g;
const int N = (int)2e5 + 5;
bool vis[N];
bool cycle[N];
stack<int> st;
bool iscycle = 0;
void dfs(int u, int pu) {
    vis[u] = 1;
    st.push(u);
    for (int v : g[u]) {
        if (iscycle)return;
        if (v == pu)continue;
        if (vis[v]) {
            iscycle = 1;
            while (1) {
                int h = st.top(); st.pop();
                cycle[h] = 1;
                if (h == v)break;
            }
            return;
        }
        else dfs(v, u);
    }
    if (iscycle)return;
    st.pop();
}
int dfs2(int u, int pu) {
    int ret = 1;
    for (int v : g[u]) {
        if (!cycle[v] && v != pu) {
            ret += dfs2(v, u);
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        iscycle = 0;
        memset(vis, 0, sizeof(vis));
        memset(cycle, 0, sizeof(cycle));
        g.clear();
        g.resize(n + 1);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (cycle[i]) {
                int c = dfs2(i, 0);// number of node of tree(each root is node on cycle)
                ans += 1LL*c * (c - 1) / 2;
                ans += 1LL*c * (n - c);
            }
        }
        cout << ans << "\n";
    }
}