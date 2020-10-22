#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
const int N = 1e6 + 2;
typedef pair<int, int> pi;
ll seg[2 * N];
int n, m, tsiz, k;
void init() {
    for (int i = n - 1; i >= 1; i--)seg[i] = seg[i << 1] + seg[i << 1 | 1];
}
void update(int p, ll val) { // plus
    for (seg[p += N] += val; p > 1; p >>= 1)seg[p >> 1] = seg[p] + seg[p ^ 1];
}

ll query(int l, int r) { //[l,r]
    r++;
    ll ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1)ret += seg[l++];
        if (r & 1)ret += seg[--r];
    }
    return ret;
}
// seg size N must be power of 2(beacuse of left and right)
int findkth(int k) {// k 번째로 작은element의 인덱스를 return
    int i = 1;
    while (i < N) {
        if (seg[i * 2] >= k)i *= 2;
        else {
            k -= seg[i * 2];
            i *= 2; i++;
        }
    }
    return i - N;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    n++;
    int s = 0;
    for (int i = 1; i < n; i++){
        cin >> seg[i+n];
    }
    init();
    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)update(b, c);
        else cout << query(b, c+1) << "\n";
    }
}