#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int n;
vector<int> nv(int n) {
    vector<int> v;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            while (n % i == 0)n /= i;
            v.push_back(i);
        }
    }
    if (n > 1)v.push_back(n);
    sort(v.begin(), v.end());
    return v;
}
int a[1001], c[1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(c, 0, sizeof(c));
        int sn = 0;
        set<int> clv[13];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            vector<int> v = nv(a[i]);
            bool isin = 0;
            for (int j : v) {
                bool isfi = 0;
                for (int k = 0; k < sn; k++) {
                    if (clv[k].find(j) != clv[k].end()) {
                        for (int l : v) {
                            clv[k].insert(l);
                        }
                        c[i] = k;
                        isfi = 1;
                        isin = 1;
                    }
                }
                if (isfi)break;
            }
            if (!isin) {
                for (int j : v) {
                    clv[sn].insert(j);
                }
                c[i] = sn++;
            }
        }
        cout << sn<< "\n";
        for (int i = 0; i < n; i++)cout << c[i] + 1 << " ";
        cout << "\n";
    }
}