#include <bits/stdc++.h>
using namespace std;
int p[100001];
int find(int x){
    if(p[x]<0)return x;
    return p[x]=find(p[x]);
}
void merge(int a,int b){
    a =find(a); b= find(b);
    if(a==b)return;
    p[a] += p[b];
    p[b] = a;
}
set<int> s;
priority_queue<int> pq;
int n , m;
int a,b,k, ans;
int main(){
    cin >> n >> m;
    memset(p,-1,sizeof(p));
    for(int i= 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        merge(u,v);
    }
    cin >> a >> b >> k;
    a =find(a); b= find(b);
    s.insert(a); s.insert(b);
    ans = abs(p[a]);
    for(int i = 1; i <= n; i++){
        int now = find(i);
        if(s.find(now) == s.end()){
            pq.push(-p[now]);
            s.insert(now);
        }
    }
    while(k&&pq.size()){
        ans +=pq.top();pq.pop();
        k--;
    }
    cout << ans;
}