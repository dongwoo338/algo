#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int n, as,bs;
void bfs(int s,vector<int>& ve){
    queue<int> q;
    q.push(s);
    ve[s]=0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0; i < 2; i++){
            int v=0;
            if(i==0) v = u + (1<<ve[u]);
            else v = u - (1<<ve[u]);
            if(v<=0 || v>n)continue;
            if(ve[v]!=-1)continue;
            ve[v] = ve[u]+1;
            q.push(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> as >> bs;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i =1; i <= n ; i++){
        a[i]=b[i]=-1;
    }
    bfs(as,a);
    bfs(bs,b);
    int ans = 5000000;
    for(int i = 1; i <=n;i++){
        if(a[i]>=1&&b[i]>=1){
            ans =min(ans,max(a[i],b[i]));
        }
    }
    if(ans==5000000)cout <<-1;
    else cout << ans;
}