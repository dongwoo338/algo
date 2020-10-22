#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int v,n;
vector<vector<int>>adj;
int sz[200001]; // 
ll dp[200001];
ll ans;
void dfs1(int v,int p=-1){
    sz[v]=1;
    for(int to:adj[v]){
        if(to==p)continue;
        dfs1(to,v);
        sz[v]+=sz[to];
    }
}
void dfs2(int v, int p=-1){
    dp[v]=sz[v];
    for(int to : adj[v]){
        if(to==p)continue;
        dfs2(to,v);
        dp[v]+=dp[to];
    }
}
void reroot(int v,int p = -1){
    ans = max(dp[v],ans);
    for(int to : adj[v]){
        if(to == p)continue;
        // remover to at v
        dp[v] -= dp[to];
        dp[v] -= sz[to];
        sz[v] -= sz[to];
        sz[to] += sz[v];
        dp[to] += sz[v];
        dp[to] += dp[v];
        reroot(to,v);
        dp[to] -= dp[v];
        dp[to] -= sz[v];
        sz[to] -= sz[v];
        sz[v] += sz[to];
        dp[v] += sz[to];
        dp[v] += dp[to];     
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    adj.resize(n);
    for(int i =0; i < n- 1; i++){
        int a,b;
        cin>> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0);
    dfs2(0);
    reroot(0);
    cout << ans << "\n";
}