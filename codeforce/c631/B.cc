#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int t,n;
int a[200001];
bool pa[200001];
bool pb[200001];
ll sega[2*200001];
ll segb[2*200001];
void aupdate(int p, ll val) {
    for (sega[p += n] = val; p > 1; p >>= 1)sega[p >> 1] = sega[p] && sega[p ^ 1];
}
void bupdate(int p, ll val) {
    for (segb[p += n] = val; p > 1; p >>= 1)segb[p >> 1] = segb[p] && segb[p ^ 1];
}
ll aquery(int l, int r) {
    ll ret = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)ret &= sega[l++];
        if (r & 1)ret &= sega[--r];
    }
    return ret;
}
ll bquery(int l, int r) {
    ll ret = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)ret &= segb[l++];
        if (r & 1)ret &= segb[--r];
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        bool ispos = 1;
        for(int i =0; i < n; i++){
            cin >> a[i];
        }
        for(int i =0; i < n; i++){
            aupdate(a[i], 1);
            bupdate(a[n-i-1], 1);
            if(aquery(1,i+2))pa[i]=1;
            if(bquery(1,i+2))pb[n-i-1]=1;
        }
        vector<pi>ans;
        for(int i =0; i <n - 1; i++){
            if(pa[i]&&pb[i+1]){
                ans.push_back({i+1,n-i-1});
            }
        }
        cout << ans.size() << "\n";
        for(auto k : ans){
            cout << k.first << " "<<k.second << "\n";
        }
        for(int i =0; i <= n; i++){
            pa[i]=pb[i]=0;
        }
        for(int i = 1; i <= 2*n; i++){
            sega[i]=segb[i] =0;
        }
    }
}