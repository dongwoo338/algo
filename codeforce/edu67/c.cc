#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int a[300001];
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    priority_queue<int> pq;
    for(int i =0; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        pq.push(a[i]-a[i-1]);
    }
    k--;
    while(!pq.empty()){
        ll h= pq.top();
        pq.pop();
        if(k)k--;
        else ans += h;
    }
    cout << ans;
}