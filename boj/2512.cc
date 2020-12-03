#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
vector<ll>v;
ll n,c;
ll vals(ll x){
    ll ret= 0;
    for(auto &i : v){
        ret += min(i,x);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ll maxt=0;
    for(int i =0; i < n; i++){
        ll k;
        cin >>k;
        maxt=max(maxt,k);
        v.push_back(k);
    }
    cin>> c;
    ll lo=0, hi = maxt;
    ll ans=0;
    while(lo<hi){
        ll mid= (lo+hi)/2+1;
        if(vals(mid)<=c){
            ans =max(ans,mid);
            lo=mid;
        }
        else hi =mid-1;
    }
    cout << ans;
}