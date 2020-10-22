#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
double ans;
int t, n, m;
int uf[501];
double dist(pi& p1, pi& p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
int find(int x) {
    if (uf[x] < 0)return x;
    return uf[x] = find(uf[x]);
}
void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b)return;
    uf[b] = a;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout.precision(33);
    cin >> t;
    while (t--) {
        ans = (double)0;
        cin >> n >> m;
        vector<pi>cord;
        memset(uf, -1, sizeof(uf));
        vector<tuple<double, int, int>> e;
        int ncnt = 0;
        for (int i = 0; i < m; i++) {
            int xi, yi;
            cin >> xi >> yi;
            cord.push_back({ xi,yi });
            for (int j = 0; j < cord.size() - 1; j++) {
                e.push_back({ dist(cord[i],cord[j]),j,i, });
            }
        }
        sort(e.begin(), e.end());
        for (auto& [c, a, b] : e) {
            ans =c;
            ncnt++;
           if(ncnt==m-n)break;
        }
        cout << ans << "\n";
    }
}