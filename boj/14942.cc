#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n ,m,k;
ll f[100001];
pair<ll,ll> p[100001][22];
vector<vector<pi>>adj(100001);
void dfs(int u,int pu,ll pd){
    p[u][0] = {pu,pd};
    for(auto k : adj[u]){
        if(k.first == pu)continue;
        dfs(k.first, u, k.second);
    }
}
ll Q(int s,ll x){
    for(int i=21;i>=0; i--){
        if(p[s][i].first ==0)continue;
        if(x>=p[s][i].second){
            x -= p[s][i].second;
            s = p[s][i].first;
        }
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)cin >> f[i];
    for(int i =0; i < n - 1; i++){
        int a, b;
        ll d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    dfs(1,0,0);
    for(int i=1; i<=21;i++){
        for(int j =1; j <=n; j++){
            auto md = p[j][i-1];
            ll newd = md.second;
            if(md.first==0)continue;
            if(p[md.first][i-1].first==0)continue;
            int nep =p[md.first][i-1].first;
            newd += p[md.first][i-1].second;
            p[j][i] = {nep,newd};
        }
    }
    for(int i =1; i <=n ; i++){
        cout << Q(i,f[i]) <<"\n";
    }
}