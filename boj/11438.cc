// RMQ를 사용한 lca 구하기
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
const int sMAX = 17;
const int N = 100001;
typedef pair<int,int> pi;
int n , m;
vector<vector<int>>adj;
pair<int,int> SPT[sMAX][2*N];
int d[N];
int pw2[sMAX], lg2[N];
int idx[N];
//e~s
vector<int> euv;
void dfs(int u,int pv){ // d[0] = -1;
    euv.push_back(u);
    d[u] = d[pv]+1;
    idx[u]=euv.size()-1;
    for(int k : adj[u]){
        if(k == pv)continue;
        dfs(k,u);
        euv.push_back(k);
    }
}
void sparsetable_build(){
    pw2[0] = 1;
    for(int k = 1; k < sMAX; k++)pw2[k] = pw2[k -1]*2;
    memset(lg2,-1,sizeof(lg2));
    for(int i =0; i < sMAX; i++) if(pw2[i]<N*2) lg2[pw2[i]]=i;
    for(int i =1; i < N*2; i++)if(lg2[i] == -1) lg2[i] =lg2[i-1];
    for(int i =0; i < 2*N;i++)SPT[0][i] = {d[euv[i]],i};
    
    for(int )
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    adj.resize(n+1);
    for(int i=0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    d[0]=-1; // d[1] must be 0. so d[0]=-1
    dfs(1,0);
}