#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
string s;
int ans = 0;
int n;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+')++x;
        else {
            ans += (x - 1);
            ans = max(ans, 0);
            x = 0;
        }
    }
    if (s[n - 1] == '+') {
        ans += x;
        ans = max(ans, 0);
        x = 0;
    }
    cout << ans;
}