#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
vector<vector<pi>>adj;
int ans[100001];
int deg[100001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(ans,-1,sizeof(ans));
    int n;
    cin >> n;
    int x= 0;
    adj.resize(n);
    for(int i =0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        deg[a]++;deg[b]++;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    for(int i=0; i < n ; i++){
        if(deg[i]>=3){
            for(auto k : adj[i]){
                ans[k.second]=x++;
            }
            break;
        }
    }
    for(int i=0; i < n - 1; i++){
        if(ans[i]==-1)ans[i]=x++;
        cout << ans[i] << " ";
    }
}