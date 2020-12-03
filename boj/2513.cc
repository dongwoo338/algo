#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, s;
    vector<pi>fv, sv;
    cin >> n >> k >> s;
    for (int fe, se; n--;) {
        cin >> fe >> se;
        if (fe < s)fv.push_back({ fe,se });
        else sv.push_back({ fe,se });
    }
    sort(fv.begin(), fv.end());
    sort(sv.begin(), sv.end());
    reverse(sv.begin(), sv.end());
    int cnt = 0;// 탄 인원
    ll ans = 0;
    int ind = 0;
    while (1 && sv.size()) {
        if (ind >= sv.size())break;
        ll hd = 2 * (sv[ind].first - s);
        sv[ind].second--;
        if (sv[ind].second == 0)ind++;
        cnt = 1;
        while (cnt < k) {
            if (ind >= sv.size())break;
            sv[ind].second--;
            if (sv[ind].second == 0)ind++;
            cnt++;
        }
        ans += hd;
    }
    ind = 0;
    while (1 && fv.size()) {
        if (ind >= fv.size())break;
        ll hd = 2 * (s - fv[ind].first);
        fv[ind].second--;
        if (fv[ind].second == 0)ind++;
        cnt = 1;
        while (cnt < k) {
            if (ind >= fv.size())break;
            fv[ind].second--;
            if (fv[ind].second == 0)ind++;
            cnt++;
        }
        ans += hd;
    }
    cout << ans;
}