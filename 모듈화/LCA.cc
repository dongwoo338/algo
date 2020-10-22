const int N = 100001;
const int RN = 21;
int p[N][RN+1];
int d[N];
int n;
void dfs(int u, int pu) { // depth and p[i][0](parent)
    d[u] = d[pu] + 1;
    p[u][0] = pu;
    for (int v : g[u]) {
        if (v == pu)continue;
        dfs(v, u);
    }
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
    if (d[v] > d[u])swap(u, v);
    int dd = d[u] - d[v];

    // make depth of U (to V) (make u,v same depth)
    for (int i = RN; i >= 0; i--) {
        if ((1 << i) <= dd) {
            dd -= (1 << i);
            u = p[u][i];
        }
    }
    if (u == v)return u;

    for (int i = RN; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

int dist(int u, int v) { // find distnace two node in tree
    return d[u] + d[v] - 2 * d[LCA(u, v)];
}