#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
int a[3001];
int ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ,k;
    cin >> n >> k;
    map<int,int>mp;
    priority_queue<int>pq;
    for(int i= 0; i < n; i++)cin>> a[i];
    for(int i= 1; i < n; i++){
        pq.push(a[i]-a[i-1]);
    }
    pq.push(0);
    for(int i =0; i < k -1; i++)pq.pop();
    while(!pq.empty()){
        ans += pq.top(); pq.pop();
    }
    cout << ans;
}