#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int d[501];
int n , m;
int ans;
vector<vector<int>>adj;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    for(int i =0; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(d,-1,sizeof(d));
    queue<int> q;
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v : adj[u]){
            if(d[v]==-1){
                d[v] =d[u]+1;
                q.push(v);
            }
        }
    }
    for(int i = 1; i<=n;i++){
        if(d[i]==1||d[i]==2)ans++;
    }
    cout << ans;
}