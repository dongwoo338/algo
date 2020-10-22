#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
typedef pair<int, int> pi;
ll fibo[1000001];
map<ll, ll>mp;
ll rec;
ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
ll g(ll a) {
    if (a <= 1000000)return fibo[a];
    if (mp.count(a)) return mp[a];
    rec++;
    ll fi = a >> 1;
    ll si = a - fi;
    ll ret = 0;
    ret = ((g(fi) * g(si + 1)) % MOD + (g(fi - 1) * g(si)) % MOD) % MOD;
    mp.insert({ a,ret });
    return ret;
}
ll a, b;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fibo[0] = 0; fibo[1] = 1;
    for (int i = 2; i <= 1000000; i++)fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    cin >> a >> b;
    cout << g(gcd(a, b));
}