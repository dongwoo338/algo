#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n , m ;
const int N= 100005;
int bc[N], vis[N];
vector<vector<int>> g;
void dfs(int u){
    vis[u] =1;
    for(int v : g[u]){
        if(!vis[v])dfs(v);
        else bc[u]++;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    g.resize(n+1);
    while(m--){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    bool ans =1;
    for(int i= 1; i <= n; i++)if(bc[i]>=2)ans=0;
    if(ans) cout << "Cactus";
    else cout << "Not cactus";
}