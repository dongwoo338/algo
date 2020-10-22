#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int seg[200002];
int n, m ;
int s[200002], e[200002];
vector<vector<int>> adj;
int clk = -1;
void dfs(int u){
    s[u] =++clk;
    for(int v : adj[u]){
        if(s[v])continue;
        dfs(v);
    }
    e[u]=clk;
}
void update(int l, int r, int val) {
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) seg[l++] += val;
        if (r & 1) seg[--r] += val;
    }
}
ll query(int p) {
    ll res = 0;
    for (p += n; p > 0; p >>= 1)res += seg[p];
    return res;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    for(int i =1; i <= n ; i++){
        int par;
        cin >> par;
        if(i==1)continue;
        adj[par].push_back(i);
    }
    dfs(1);
    for(int i =0; i < m ; i++){
        int q,a,b;
        cin >> q >> a;
        if(q==1){
            cin >> b;
            update(s[a],e[a],b);
        }
        if(q==2){
            cout << query(s[a])<<"\n";
        }
    }
}