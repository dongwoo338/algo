#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
struct edge{
    int v1,v2,d;
    edge(int a,int b,int c):v1(a), v2(b),d(c){}
    bool operator<(const edge& O){
        return d<O.d;
    }
};
int n , m, sz, ans;
int uf[10001];
vector<edge> v;
int find(int x){
    if(uf[x]<0)return x;
    return uf[x] = find(uf[x]);
}
bool merge(int a,int b){
    a = find(a); b= find(b);
    if(a==b)return 0;
    uf[b]=a;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n>> m;
    memset(uf,-1,sizeof(uf));
    for(int i =0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edge(a,b,c));
    }
    sort(v.begin(),v.end());
    for(auto i : v){
        if(merge(i.v1,i.v2)){
            sz++;
            ans+=i.d;
        }
        if(sz==n-1)break;
    }
    cout << ans;
}