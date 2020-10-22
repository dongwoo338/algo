#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
priority_queue<int>pq;
ll ans;
bool isok=1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector<pi>v;
    for(int i =0; i < n ; i++){
        v.push_back({i,m});
    }
    for(int i =0; i < m; i++){
        int k;
        pq.push(k);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    while(!pq.empty()){
        
    }
}