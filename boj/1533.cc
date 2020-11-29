#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
typedef vector<vector<ll>> matrix;
int n, s, e, t;
const int MOD = 1000003;
matrix a, b;
matrix mul(matrix& a, matrix& b) {
    matrix ret(n*5,vector<ll>(n*5));
    for (int i = 0; i < n * 5; i++)ret[i].resize(n*5);
    for (int i = 0; i < n * 5; i++) {
        for (int j = 0; j < n * 5; j++) {
            for (int k = 0; k < n * 5; k++) {
                ret[i][j] = (ret[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s >> e >> t;
    a=matrix(n*5,vector<ll>(n*5));
    b=matrix(n*5,vector<ll>(n*5));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            int e = s[j] - '0';
            if (e == 0)continue;
            e--;
            int jj = i;
            while (e--) {
                a[jj][jj+n] = 1;
                jj += n;
            }
            a[jj][j] = 1;
        }
    }
    for (int i = 0; i < n * 5; i++)b[i][i] = 1;
    for (int i = 0; i < 30; i++) {
        if (i != 0)a = mul(a, a);
        if (t & (1 << i)) {
            b = mul(b, a);
        }
    }
    cout << b[s-1][e-1];
}