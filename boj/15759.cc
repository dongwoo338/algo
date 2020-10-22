#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1000*250+1;
const int INF = 1e9;
typedef pair<int,int> pi;
ll dp[MAX];
ll rans;
int n ,k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0; i < MAX; i++)dp[i]=INF;
    vector<pi> v;
    for(int i =0; i < n; i++){
        ll w, t;
        cin >> w >> t;
        v.push_back({w,t});
    }
    sort(v.begin(),v.end());
    for(int i =0; i < n; i++){
        ll w, t;
        w =v[i].first; t = v[i].second;
        dp[0]=0;
        for(int i = MAX-1; i-t>=0; i--){
            if(dp[i-t] < INF)dp[i] = min(dp[i], dp[i - t]+w);
            if(dp[i]>=k && dp[i] < INF){
                 rans =max(rans, 1LL*i*1000/dp[i]);
            }
        }
    }
    cout << rans;
}