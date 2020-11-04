#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
vector<vector<pi>>g;
int d[1001];//2->i mindist
int dp[1001];
int dfs(int u){
    int &ret= dp[u];
    if(ret!=-1)return ret;
    ret =0;
    int nd= 0;
    for(auto &[v,w] : g[u]){
        if(d[v]<d[u])nd += dfs(v);
    }
    if(nd==0){
        if(u==2)ret=1;
    }
    else ret +=nd;
    return dp[u];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m;
    cin >> n >> m;
    g.resize(n+1);
    for(int i =0; i < m; i++){
        int u,v,c;
        cin >> u >> v>>c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
    fill(d,d+1001,MAX);
    priority_queue<pi>pq;//-d,node
    pq.push({0,2});

    d[2]=0;
    while(pq.size()){
        auto [w,u]=pq.top();
        pq.pop();
        if(-w>d[u])continue;
        for(auto [v,nd] : g[u]){
            if(d[u]+nd<d[v]){
                d[v] = d[u]+nd;
                pq.push({-d[v],v});
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(1);
}