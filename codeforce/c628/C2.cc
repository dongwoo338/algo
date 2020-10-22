#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int deg[100001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<pi>edge;
    int n;
    cin >> n;
    for(int i=0; i < n -1 ;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        deg[a]++; deg[b]++;
        edge.push_back({a,b});
    }
    vector<int>ans(n-1,-1);
    int x=0;
    for(int i =0; i < n- 1; i++){
        int u = edge[i].first, v = edge[i].second;
        if(deg[u]==1||deg[v]==1)ans[i] =x++;
    }
    for(int i =0; i < n - 1; i++)cout << (~ans[i] ? ans[i] : x++) << "\n";
}