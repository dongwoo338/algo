#include<bits/stdc++.h>
using namespace std;
int ans;
vector<int> sobun(int x) {
    vector<int> v;
    for (int i = 2; i * i <= x; i++) {
        if ((x % i) == 0) {
            while ((x % i) == 0) {
                v.push_back(i);
                x /= i;
            }
        }
    }
    if (x >= 2)v.push_back(x);
    return v;
}
int main() {
    int n;
    cin >> n;
    vector<int> v = sobun(n);
    set<int> s;
    s.insert(1);
    for (int i : v) {
        vector<int> tv;
        for (auto j : s) {
            tv.push_back(j * i);
        }
        for (int j : tv)s.insert(j);
    }
    int pre;
    for (auto k : s) {
        if (k == 1) {
            pre = k;
            continue;
        }
        ans += (k - pre) * (n / pre);
        pre = k;
    }
    cout << ans + 1;
}