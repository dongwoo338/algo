#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    if (n & 1) {
        n /= 2;
        if (n & 1)ans = 0;
    }
    else {
        n /= 2;
        if (n % 2 == 0)ans = 0;
    }
    cout << ans;
}