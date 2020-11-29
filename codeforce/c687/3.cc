#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
ll dp[100001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        string s, ss;
        s = "1";
        cin >> ss;
        s += ss;
        ll x, y;
        cin >> x >> y;
        memset(dp, 0, sizeof(dp));
        ll ans= (ll)2e9;
        for (int i = n; i >= p; i--) {
            if (i + k > n) {
                if (s[i] == '1')dp[i] = 0;
                else dp[i] = x;
                ans=min(ans,dp[i]+(i-p)*y);
                continue;
            }
            if (s[i] == '0') {
                dp[i] = dp[i+k]+x;
            }
            else {
                dp[i] = dp[i+k];
            }
            ans=min(ans,dp[i]+(i-p)*y);
        }
        cout << ans << "\n";
    }
}