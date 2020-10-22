#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const ll MOD = 998244353;
int n , k;
int a[200001];
set<ll> s;
priority_queue<ll> pq;
ll ans;
ll sans = 1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pq.push(a[i]);
    }
    while(k--){
        ans+=pq.top();
        s.insert(pq.top());
        pq.pop();
    }
    vector<ll> b;
    for(int i=1; i <=n; i++){
        if(s.find(a[i])!=s.end()){
            b.push_back(i);
        }
    }
    for(int i =1; i < b.size(); i++){
        sans = (sans * (b[i] - b[i-1]))%MOD;
    }
    cout << ans << " "<<sans;
}