#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const int N = 200001;
typedef pair<int, int> pi;
int segmax[2 * N];
int segmin[2 * N];
int n, m, tsiz, k;
void init() {
    for (int i = n - 1; i >= 1; i--){
        segmax[i] = max(segmax[i << 1],  segmax[i << 1 | 1]);
        segmin[i] = min(segmin[i << 1],  segmin[i << 1 | 1]);
    }
}

int maxquery(int l, int r) { //[l,r]
    r++;
    int ret = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1){
            ret = max(ret, segmax[l++]);
        }
        if (r & 1)ret = max(ret,segmax[--r]);
    }
    return ret;
}
int minquery(int l, int r) { //[l,r]
    r++;
    int ret = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1){
            ret = min(ret, segmin[l++]);
        }
        if (r & 1)ret = max(ret,segmin[--r]);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ps = 0;
        string s;
        cin >> s;
        for(int i =0; i < n; i++){
            if(s[i]=='-')ps--;
            else ps++;
            segmax[n+i]=segmin[n+i]=ps;
        }
        init();
        while(m--){
            int l, r;
            cin >> l >> r;
            l--; r--;
            int maxx =0, minx= 0;
            int ans= 1;
            if(l!=0){
                maxx = maxquery(0,l-1);
                minx = minquery(0,l-1);
            }
            if(r!=n-1){
                if(l!=0){
                    maxx = max(maxx, maxquery(r+1,n-1)+segmax[n+l-1]);
                    minx = min(minx, minquery(r+1,n-1)+segmin[n+l-1]);
                }
                else {
                    maxx= maxquery(r+1,n-1); 
                    minx= minquery(r+1,n-1);
                }
            }
            ans += max(0,maxx);
            if(minx<0)ans-=minx;
            cout << ans << "\n";
        }
    }
}