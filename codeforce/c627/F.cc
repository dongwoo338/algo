#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int n;
int c[200001];
int dp[200001];
int ans[200001];
const int nv = -200005;
vector<vector<int>>v;
void rec(int x, int p){
    dp[x]=c[x];
    for(int next : v[x]){
        if(next == p)continue;
        rec(next,x);
        dp[x] += max(dp[next],0);
    }
}
// when vectex x and its child to
// reroot(to as a root)
void dfs2(int x,int p){
    ans[x] = dp[x];
    for(int to: v[x]){
        if(to == p)continue;
        dp[x] -= max(0,dp[to]);
        dp[to] += max(0, dp[x]);
        dfs2(to,x);
        dp[to] -= max(0,dp[x]);
        dp[x] += max(0, dp[to]);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i<= n; i++){
        int k;
        cin >> k;
        if(k)c[i]=1;
        else c[i]=-1;
    }
    v.resize(n+1);
    for(int i= 1; i <= n; i++)dp[i]=nv;
    for(int i=0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    rec(1,-1);
    dfs2(1,-1);
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
}