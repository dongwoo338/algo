#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
vector<vector<int>>g;
const int N = 10005;
int a[N],b[N],vis[N];
int dfs(int u){
    vis[u]=1;
    for(int v : g[u]){
        if(!b[v]||(!vis[b[v]]&&dfs(b[v]))){
            a[u]=v;
            b[v]=u;
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ,m;
    cin >> n >> m;
    g.resize(n+1);
    for(int i=0; i < m; i++){
        int u,v;
        cin >> u >>v;
        g[u].push_back(v);
    }
    int match=0;
    for(int i =1; i<=n; i++){
        if(a[i]==0){
            memset(vis,0,sizeof(vis));
            match+=dfs(i);
        }
    }
    cout << n-match;
}