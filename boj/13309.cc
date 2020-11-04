#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
const int RN = 20;
int n, q;
int num[N];//for euler tour
vector<int>g[N];
typedef long long ll;
int clk = -1;
int seg[3 * N], dep[N], s[N], e[N];// ett
int p[N][RN];// LCA
bool erased[N];
void dfs(int u, int pu) { // depth and p[i][0](parent)
    s[u] = ++clk;
    dep[u] = dep[pu] + 1;
    p[u][0] = pu;
    for (int v : g[u]) {
        if (v == pu)continue;
        dfs(v, u);
    }
    e[u] = clk;
}
void lcainit() {//p[i][0] - > fill all sparse table
    for (int j = 1; j < RN; j++) {
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
}

int LCA(int u, int v) {
    //main tain depth u >= v
    if (dep[v] > dep[u])swap(u, v);
    int dd = dep[u] - dep[v];

    // make depth of U (to V) (make u,v same depth)
    for (int i = RN-1; i >= 0; i--) {
        if ((1 << i) <= dd) {
            dd -= (1 << i);
            u = p[u][i];
        }
    }
    if (u == v)return u;

    for (int i = RN-1; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}
int Q(int p) { 
    p += n;
    int ret = 0;
    for (int i = p; i >= 1; i >>= 1) ret = max(ret, seg[i]);
    return ret;
}
bool QQ(int u, int v) {
    int lca = LCA(u, v);
    int uv = Q(s[u]);
    int vv = Q(s[v]);
    int lv = Q(s[lca]);
    return lv >= max(uv, vv);
}
void update(int l, int r, int val) { //[l,r]
    r++;
    ++clk;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            seg[l] = max(seg[l],val); 
            l++;
        }
        if (r & 1) {
            --r;
            seg[r] = max(seg[r], val);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    erased[1] = 1;
    cin >> n >> q;
    for (int i = 0; i < 2 * N; i++)seg[i] = 1;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 0);
    lcainit();
    for (int i = 0; i < q; i++) {
        int x, u, v;
        cin >> u >> v >> x;
        if (x == 1) {
            if (QQ(u, v)) {
                cout << "YES" << "\n";
                if (!erased[u]) {
                    update(s[u], e[u], dep[u]);
                    erased[u] = 1;
                }
            }
            else {
                cout << "NO" << "\n";
                if (!erased[v]) {
                    update(s[v], e[v], dep[v]);
                    erased[v] = 1;
                }
            }
        }
        else {
            if (QQ(u, v))cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}