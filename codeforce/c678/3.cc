#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int a[1001];// 1 small 2 big
ll fac[2001];
int n, m, k;
bool canfind = 0;
const ll MOD = (ll)1e9 + 7;
int ln, sn;
void rec(int s, int e) {
    debug(s,e);
    if(s>=e){
        canfind=1;
        return;
    }
    int mid = (s + e) / 2;
    if (a[mid] == 1 && a[mid]==3) {
        rec(s, mid);
    }
    else if(a[mid]==2){
        rec(mid+1,e);
    }
    else {
        if (k <= mid) {//l
            if (!sn) {
                return;
            }
            a[mid]=2;
            sn--;
            rec(s, mid);
        }
        else {//r
            if (!ln) {
                return;
            }
            a[mid]=1;
            ln--;
            rec(mid + 1, e);
        }
    }
}

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
    for (int i = 1; i <= 2000; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    cin >> n >> m >> k;
    a[k] = n;
    ll ans = 1;
    sn = m - 1;
    ln = n - m;
    a[k]=3;
    rec(0, n - 1);
    int ssel=0, lsel=0;
    for(int i =0; i < n; i++)cout << a[i]<<" ";
    for(int i =0; i <= n; i++){
        if(a[i]==2)lsel++;
        else ssel++;
    }
    int facnum = n - 1 -ssel -lsel;
    cout << canfind;
    if (!canfind)cout << 0;
    else {
        ll ans = 1;
        ans = (ans * ncr(sn, ssel)) % MOD;
        ans = (ans * ncr(ln, lsel)) % MOD;
        ans = (ans * fac[facnum]) % MOD;
        cout << ans;
    }
}