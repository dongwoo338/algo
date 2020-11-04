#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        if(a%b!=0){
            cout << a<<"\n";
            continue;
        }
        vector<pair<ll,ll>>v;
        ll pb= b;
        for(ll i = 2; i*i<=pb; i++){
            if(pb%i==0){
                ll x= 0;
                while(pb%i==0){
                    pb/=i;
                    x++;
                }
                v.push_back({i,x});
            }
        }
        if(pb>=2)v.push_back({pb,1});
        ll ans = (ll)-2e18;
        for(auto &[x,y] : v){
            ll rx = x;
            while(rx <= a){
                if(a%rx==0 && rx%b!=0){
                    ans=max(ans,a/rx);
                }
                rx*=x;
            }
        }
        cout << ans<<"\n";
    }
}