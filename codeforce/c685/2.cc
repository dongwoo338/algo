#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string st;
        cin >> st;
        for (int i = 0; i < m; i++) {
            int s, e;
            cin >> s >> e;
            int po = e - 1;
            int isok = 0;
            int nj = 0;
            for (int j = n - 1; j >= 1; j--) {
                if (po == s - 1) {
                    isok = 1;
                    nj = j;
                    break;
                }
                if (st[j] == st[po])po--;
            }
            if (isok) {
                for (int j = 0; j < nj; j++) {
                    if (st[j] == st[po]) {
                        isok++;
                        break;
                    }
                }
            }
            if (isok == 2)cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
}