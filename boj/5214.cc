#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int d[123456];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m,k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n+k+1);
    memset(d,-1,sizeof(d));
    for(int i = n +1; i <= n+k; i++){
        for(int j =0; j < m; j++){
            int tt;
            cin >> tt;
            adj[tt].push_back(i);
            adj[i].push_back(tt);
        }
    }
    d[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(d[v] != -1)continue;
            if(u>n)d[v]=d[u]+1;
            else d[v]=d[u];
            q.push(v);
        }
    }
    if(d[n]==-1)cout << -1;
    else cout << d[n]+1;
}