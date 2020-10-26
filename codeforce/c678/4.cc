#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int n;
const int N = (int)2e5 + 5;
ll dp[N], a[N];
vector<vector<int>>g;
ll dfs(int u) {
    if (g[u].empty())dp[u] = a[u];
    else {
        vector<ll>vt;
        ll maxt = (int)-1e9;
        ll sumofdiff = 0;
        for (int v : g[u]) {
            vt.push_back(v);
            maxt = max(maxt, dp[v]);
        }
        for (int v : vt) {
            sumofdiff += (maxt - dp[v]);
        }
        if (a[u] <= sumofdiff) {
            dp[u] = maxt;
        }
        else {
            a[u] -= sumofdiff;
            dp[u] = maxt;
            dp[u] += (a[u] / vt.size());
            if (a[u] % vt.size())dp[u]++;
        }
    }
    return dp[u];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)cin >> a[i];
    cout << dfs(1);
}