#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
ll h;
int n;
ll ps[200001];
ll lcnt = 1e13;
ll cycnt;
ll ans;
bool isok=1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> h >> n;
    for (int i = 0; i < n; i++) {
        cin >> ps[i];
        if (i != 0)ps[i] += ps[i - 1];
        lcnt = min(ps[i], lcnt);
    }
    cycnt = ps[n - 1];
    h += lcnt;
    if(h>0&&cycnt>=0){
        cout << -1;
        return 0;
    }
    else{
        if(h >0){
            ll cc = (h /-cycnt);
            if(h%-cycnt)cc++;
            h += cc*cycnt;
            ans += cc*n;
        }
        h -=lcnt;
        for(int i=0; i < n; i++){
            if(h+ps[i]<=0){
                ans += (i+1);
                break;
            }
        }
        cout << ans;
    }
}