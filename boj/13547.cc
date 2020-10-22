#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int rt, n, m, ans;
struct query {
    int l, r, n;
    bool operator<(const query& o) {
        int x = r / rt;
        int y = o.r / rt;
        if (x == y) return l < o.l;
        else return x < y;
    }
}q[100001];
int a[100001];
int cnt[1000001];
int rans[100001];
void f(int ind, bool ispl) {
    if (ispl) {
        if (cnt[a[ind]]++ == 0)ans++;
    }
    else {
        if (--cnt[a[ind]] == 0)ans--;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rt = sqrt(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--; q[i].r--;
        q[i].n = i;
    }
    sort(q, q + m);
    int lo = 0, hi = -1;
    for (int i = 0; i < m; i++) {
        while (q[i].r > hi)f(++hi, 1);
        while (q[i].r < hi)f(hi--, 0);
        while (q[i].l < lo)f(--lo, 1);
        while (q[i].l > lo)f(lo++, 0);
        rans[q[i].n] = ans;
    }
    for (int i = 0; i < m; i++)cout << rans[i] << "\n";
}