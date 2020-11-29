#include<bits/stdc++.h>
using namespace std;
int tt,n;
const int N= 1001;
int s[N],d[N], a[N],b[N], t[N][N], uf[N], usz[N];//for uf
int find(int x){
    if(uf[x]<0)return x;
    return uf[x] =find(uf[x]);
}
void merge(int a,int b){
    a= find(a);
    b= find(b);
    if(a==b)return;
    uf[b] =a;
    usz[a]+=usz[b];
}
bool vis[N];
vector<vector<int>>g;
bool dfs(int u){
    vis[u]=1;
    for(int v : g[u]){
        if(b[v]==-1||(!vis[b[v]]&&dfs(b[v]))){
            a[u] =v;
            b[v] =u;
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> tt;
    while(tt--){
        cin >> n;
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        memset(uf,-1,sizeof(uf));
        fill(usz,usz+N,1);
        for(int i =1; i <=n; i++)cin >> s[i];
        for(int i =1; i <=n; i++)cin >> d[i];
        for(int i = 1; i <= n; i++){
            for(int j= i; j <=n; j++)cin >> t[i][j];
        }
        g.clear();
        g.resize(n+1);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                if(i==j)continue;
                if((s[i]==s[j]&&i<j) ||(s[i]<s[j])){
                    if(s[i]+d[i]+t[min(i,j)][max(i,j)]>s[j]){
                        g[i].push_back(j);
                    }
                }
            }
        }
        int ans=0;
        for(int i = 1; i <= n; i++){
            memset(vis,0,sizeof(vis));
            ans +=dfs(i);
        }
        for(int i =1; i <= n; i++){
            if(a[i]!=-1)merge(i,a[i]);
        }
        vector<int>anv;
        int sn=  0;
        for(int i = 1; i <= n; i++){
            if(usz[i]==ans+1){
                sn = find(i);
                break;
            }
        }
        for(int i = 1; i <= n; i++){
            if(find(i)==sn)anv.push_back(i);
        }
        cout << ans+1<<"\n";
        for(int i :anv)cout<<i<<" ";
        cout << "\n";
    }
}