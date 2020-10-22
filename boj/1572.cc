#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
ll seg[4 * 65536];
int n, k, tsiz = 1;
ll ans;
void update(int ind, int val) {
    ind += tsiz;
    seg[ind] += val;
    ind /= 2;
    while (ind > 0) {
        seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
        ind /= 2;
    }
}
long long int Kquery(ll s, ll e, ll ind, ll K) {
    if (s == e) return s;
    if (K <= seg[ind * 2]) return Kquery(s, (s + e) / 2, 2 * ind, K);
    return Kquery((s + e) / 2 + 1, e, 2 * ind + 1, K - seg[2 * ind]);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    while (tsiz < 65536)tsiz *= 2;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int tm;
        cin >> tm;
        dq.push_back(tm);
        update(tm, 1);
        if (dq.size() > k) {
            update(dq.front(), -1);
            dq.pop_front();
        }
        if (i < k -1)continue;
        int midex = dq.size() / 2 + (dq.size() & 1);
        cout << Kquery(1, tsiz, 1, midex)<<"\n";
        ans += Kquery(1, tsiz, 1, midex);
    }
    cout << ans;
}