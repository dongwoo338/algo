
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int t, n, x;
int ans;
int a[12345];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            a[k] = 1;
        }
        for (int i = 1; i < 12345; i++) {
            if (a[i])continue;
            if (!a[i]) {
                if (x) {
                    x--;
                    continue;
                }
                else {
                    ans = i -1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}