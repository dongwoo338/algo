#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
const int MOD = 998244353;
const int N = 2e5 + 4;
ll p[N]; // 10^p
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = (p[i - 1] * 10) % MOD;
    }
}