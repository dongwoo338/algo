#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
const int N = 100002;
int seg[200004];
int segsiz[200004];
int xon[N];
int pxor[N + 1];
vector<vector<int>>adj;
int n, m, clk = -1;
int s[N], e[N];
void update(int l, int r, int val) {
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) seg[l++] ^= val;
        if (r & 1) seg[--r] ^= val;
    }
}
int query(int s, int e) {
    int ret = pxor[e + 1] ^ pxor[s];
    for (s += n; s >= 1; s >>= 1) {
        if (segsiz[s] & 1)ret ^= seg[s];
    }
    for (e += n; e >= 1; e >>= 1) {
        if (segsiz[e] & 1)ret ^= seg[e];
    }
    return ret;
}
void dfs(int u) {
    s[u] = ++clk;
    for (int v : adj[u]) {
        if (v == 1 || s[v])continue;
        dfs(v);
    }
    e[u] = clk;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    // construct segsiz
    for (int i = n; i < 2 * n; i++)segsiz[i] = 1;
    for (int i = n - 1; i >= 1; i--) segsiz[i] = segsiz[i << 1] + segsiz[i << 1 | 1];
    for (int i = 1; i<=n; i++){
        int k;
        cin >> k;
        xon[s[i]+1]=k;
    }
    for (int i = 1; i <= n; i++) {//1부터니까 조심해라
        pxor[i] = pxor[i-1]^xon[i];
    }
    for (int i = 0; i < m; i++) {
        int q, a, b;
        cin >> q >> a;
        if (q == 1) {
            cout << query(s[a], e[a]) << "\n";
        }
        if (q == 2) {
            cin >> b;
            update(s[a], e[a], b);
        }
    }
}