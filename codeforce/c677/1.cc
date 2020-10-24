#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
vector<vector<pi>>g;
int d[1001][1001];
void dijkstra(int uu){ // dijkstar n times, memo in d[u][x]
    priority_queue<pi>pq;
    d[uu][uu]=0;
    pq.push({0,uu});
    while(!pq.empty()){
        auto [w,u] = pq.top();
        pq.pop();
        if(-w > d[uu][u])continue;
        for(auto& [v,w] : g[u]){
            if(d[uu][v] > d[uu][u] + w){
                d[uu][v] = d[uu][u] + w;
                pq.push({-d[uu][v],v});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m ,k;
    cin >> n >> m >> k;
    vector<pi>edges;
    vector<pi>ks(k);
    g.resize(n+1);
    fill(&d[0][0], &d[1000][1000],(int)MAX);
    for (int i =0; i <m; i++){
        int u,v,d;
        cin >> u >> v >> d;
        g[u].push_back({v,d});
        g[v].push_back({u,d});
        edges.push_back({u,v});
    }
    // dijkstra n times (fill d table)
    for(int i =1 ; i <=n; i++){
        dijkstra(i);
    }
    for(auto &x : ks)cin>>x.first>>x.second;
    // make each edges 0 O(m)
    int ans= MAX;
    
    for(auto &[x,y] : edges){
        int val=0;
        for(auto &[u,v] : ks){
            val += min({d[u][v],d[u][x]+d[y][v],d[u][y]+d[x][v]});
        }
        ans =min(ans,val);
    }
    cout << ans;
}