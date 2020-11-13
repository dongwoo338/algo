// fail...


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const int N = 1001;
vector<vector<int>>g,ng;
stack<int> st;
int scnum[N];
bool vis[N];
vector<vector<int>> sccvt; 
vector<set<int>>sv; 
int indeg[N];// scc indeg
double cost[N];
int n;
int sccnt;
void dfs(int u){
    vis[u]=1;
    for(int v : g[u]){
        if(!vis[v])dfs(v);
    }
    st.push(u);
}

void dfs2(int u){
    sccvt[sccnt].push_back(u);
    scnum[u]=sccnt;
    vis[u]=0;
    for(int v : ng[u]){
        if(vis[v])dfs2(v);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    g.resize(n);
    ng.resize(n);
    sv.resize(n);
    for(int i =0; i <n ; i++)cin >> cost[i];
    for(int i =0; i <n; i++){
        string s;
        cin >> s;
        for(int j=0; j < n; j++){
            if(s[j]=='Y'){
                g[i].push_back(j);
                ng[j].push_back(i);
            }
        }
    }
    for(int i =0; i < n; i++){
        if(!vis[i])dfs(i);
    }
    while(st.size()){
        int u = st.top(); st.pop();
        if(vis[u]){
            dfs2(u);
            sccnt++;
        }
    }

    for(int u =0; u < n; u++){
        for(int v : g[u]){
            if(scnum[u]==scnum[v])continue;
            sv[scnum[u]].insert(scnum[v]);
            indeg[scnum[v]]++;
        }
    }
    memset(vis,0,sizeof(vis));
    double ans =0, ancnt =0;
    for(int i =0; i < sccnt; i++){
        if(!indeg[i]){
            double mincost = 1e9;
            for(auto k : sccvt[i])mincost=min(mincost,cost[k]);
            ancnt++;
            ans += mincost;
        }
    }
    cout << fixed << setprecision(9)<<ans/ancnt;
}
