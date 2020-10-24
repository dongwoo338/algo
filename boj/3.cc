#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const ll MOD =998244353;
ll dp[200001];
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
ll ncr(ll n, ll r) {
    ll ret = fac[n];
    ret = (ret * mypow(fac[r], MOD - 2)) % MOD;
    ret = (ret * mypow(fac[n - r], MOD - 2)) % MOD;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 10000; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }   
    dp[1] = 10;
    for(int i = 2; i <= n; i++){
       dp[i] = dp[i-1]*i%MOD;
    }
    for(int i = n; i >= 1; i--)cout << dp[i] << " ";
}