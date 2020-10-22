#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int n ,m;
bool check[200001];
int deg[200001];
vector<vector<int>> adj;
int ans;
bool dfs(int v){
    int ret =0;
    if(deg[v]==2)ret=1;
    check[v]=1;
    for(int to : adj[v]){
        if(check[to])continue;
        ret *= dfs(to);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    adj.resize(n);
    for(int i=0 ; i <m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
    }
    for(int i= 0; i < n; i++){
        if(!check[i])ans+=dfs(i);
    }
    cout << ans;
}