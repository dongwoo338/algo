#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int clk=0;
const int N = 1e5+5;
int vis[N];
int n , m;
typedef pair<int,int> pi;
set<pi> ans;
vector<vector<int>>g;
void dfs(int u,int pu){
    int un = vis[u] = ++clk;
    int ret = (int)1e9;
    for(int v : g[u]){
        if(v==pu)continue;
        if(!vis[v]){
            dfs(v,u);
            if(un<vis[v])ans.insert({min(u,v),max(u,v)});
            else vis[u]=min(vis[u],vis[v]);
        }
        else vis[u] = min(vis[u],vis[v]);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    g.resize(n+1);
    for(int i=0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans.size()<<"\n";
    for(auto &[x,y]: ans)cout << x<<" "<<y<<"\n";
}