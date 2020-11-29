#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const int N = (int)2e6+5;
int p[N],d[N];
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
bool merge(int a, int b) {
	a = find(a); b = find(b);
    if(a==b)return 0;
	if(a!=b)p[b] = a;
    return 1;
}
vector<vector<int>>g;
int s,e;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        g.clear();
        g.resize(n+1);
        memset(p,-1,sizeof(p));
        memset(d,-1,sizeof(d));
        for(int i =0 ; i < n; i++){
            int u,v;
            cin >> u>> v;
            if(!merge(u,v)){
                s= u; e= v;
            }
            else{
                g[u].push_back(v);
                g[v].push_back(u);
            }
            d[u]=0;
            queue<int>q;
            q.push(s);
            while(q.size()){
                int u = q.front();q.pop();
                for(int v : g[u]){
                    if(d[v]==-1){
                        d[v]=d[u]+1;
                        q.push(v);
                    }
                }
            }
            ll ans= n*(n-1);
            ans -= (n-1-d[e]);
            cout << ans << "\n";
        }
    }
}