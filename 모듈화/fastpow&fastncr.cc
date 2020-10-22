#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
const ll MOD = (ll)1e9 + 7;
const int N = 4000002;
ll fac[N];
int m;
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
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i <= 4000000; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }