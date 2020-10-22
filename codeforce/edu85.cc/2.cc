#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int t, n, k;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int ans = 0;
        ll plval = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val - k >= 0) {
                plval += (val - k);
                ans++;
            }
            else pq.push(val - k);
        }
        while (!pq.empty()) {
            if (plval >= -pq.top()) {
                plval += pq.top();
                pq.pop();
                ans++;
            }
            else break;
        }
        cout << ans << "\n";
    }
}