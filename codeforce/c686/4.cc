#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
map<ll, int> sobun(ll x) {
    map<ll, int> mp;
    for (ll i = 2; i * i <= x; i++) {
        if ((x % i) == 0) {
            while ((x % i) == 0) {
                mp[i]++;
                x /= i;
            }
        }
    }
    if (x >= 2)mp[x]++;
    return mp;
}
ll mypow(ll a, ll b) {
    ll ret = 1;
    while (b--)ret *= a;
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        map<ll, int>mp = sobun(n);
        int ans = 0;
        ll elem = 0;
        for (auto k : mp) {
            if (k.second > ans) {
                ans = k.second;
                elem = k.first;
            }
        }
        cout << ans << "\n";
        
        for (int i = 0; i < ans; i++) {
            if (i == ans - 1) {
                cout << n / mypow(elem, ans-1);
            }
            else cout << elem << " ";
        }
        cout << "\n";
    }
}