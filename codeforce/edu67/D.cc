#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
ll n, m, k;
ll a[300001];
deque<ll> dq;
ll ans;
ll ps;
ll vals;
ll nvals;
int l = 1, r = 1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dq.push_back(a[i]);
        ps += a[i];
        r = i;
        vals = ps - k * ceil(((double)(r - l + 1) / (double)m));
        ans = max(vals, ans);
        while (l < r) {
            ll tps = ps - a[l];
            ll tvals = tps - k * ceil(((double)(r - l) / (double)m));
            if (tvals >= vals) {
                dq.pop_front();
                l++;
                ans = max(tvals, ans);
                vals = tvals;
                ps = tps;
            }
            else break;
        }
    }
    cout << ans;
}