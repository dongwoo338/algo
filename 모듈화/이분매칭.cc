#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int n, m;
const int N = 202;
int a[N], b[N], vis[N];
vector<int>g[N];
int match;
bool dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (b[v] == -1 || !vis[b[v]] && dfs(b[v])) {
            a[u] = v;
            b[v] = u;
            return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int c, v;
        cin >> c;
        for (int j = 1; j <= c; j++) {
            cin >> v;
            g[i].push_back(v);
        }
    }
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            memset(vis, 0, sizeof(vis));
            match += dfs(i);
        }
    }
    cout << match;
}