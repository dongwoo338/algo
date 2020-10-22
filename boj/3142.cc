#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int, int> pi;
int seg[1000001 * 2];
bool check[1000001];
map<int,int> mdp[1000001];
int n = 1000001;//(0~1000000)
void update(int p, ll val) {
    for (seg[p += n]+=val, seg[p]%=2; p > 1; p >>= 1)seg[p >> 1] = seg[p] || seg[p ^ 1];
}
map<int, int> sobun(int x) {
    if(check[x])return mdp[x];
    int ox= x;
    map<int, int> mp;
    for (int i = 2; i * i <= x; i++) {
        if ((x % i) == 0) {
            while ((x % i) == 0) {
                mp[i]++;
                x /= i;
            }
        }
    }
    if (x >= 2)mp[x]++;
    check[ox]=1;
    mdp[ox]=mp;
    return mp;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        auto mp = sobun(num);
        for (auto k : mp) {
            update(k.first,k.second);
        }
        if(seg[1])cout <<"NE"<<"\n";
        else cout <<"DA"<<"\n";
    }
}