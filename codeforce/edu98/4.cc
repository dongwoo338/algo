
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
const ll MOD = (ll) 998244353;
ll mypow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll esum=1, osum=0;
    ll ans;
    for(int i = 1; i <= n; i++){
        if(i&1){
            ans =esum;
            osum =(osum+esum)%MOD;
        }
        else{
            ans = osum;
            esum = (esum+osum)%MOD;
        }
    }
    ll bm = 1;
    bm = mypow(2,n);
    bm = mypow(bm,MOD-2);
    ans =(ans*bm)%MOD;
    cout << ans;
}