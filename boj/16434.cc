#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
ll n ,a;
struct s{
    ll fi,se,ti;
}s[123457];
bool trev(ll mhp){
    ll ta =a;
    ll thp = mhp;
    for(int i =0; i < n; i++){
        if(s[i].fi==2){
            ta += s[i].se;
            thp = min(thp+ s[i].ti ,mhp);
        }
        else{
            ll cnt = (s[i].ti-1) /ta;
            thp -= cnt*s[i].se;
            if(thp<=0)return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n  >> a;
    for(int i =0; i < n; i++){
        int w,e,t;
        cin >> w >> e >> t;
        s[i] = {w,e,t};
    }
    ll lo= 0, hi=2e18, mid=0;
    while(lo+1<hi){
        mid = lo+(hi-lo)/2;
        if(trev(mid)) hi = mid;
        else lo =mid;
    }
    cout << hi;
}