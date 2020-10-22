#include<iostream>
using namespace std;
int seg[2][200001];
int n,q;
void init() {
    for (int i = n - 1; i >= 1; i--){
        seg[0][i] = seg[0][i << 1] + seg[0][i << 1 | 1];
        seg[1][i] = seg[1][i << 1] + seg[1][i << 1 | 1];
    }
}
void update(int rp, int val) {
    val%=2;
    val^=1;
    int p =rp;
    for (seg[0][p += n] = val; p > 1; p >>= 1)seg[0][p >> 1] = seg[0][p] + seg[0][p ^ 1];
    p =rp;
    for (seg[1][p += n] = val^1; p > 1; p >>= 1)seg[1][p >> 1] = seg[1][p] + seg[1][p ^ 1];
}
int query(int c,int l, int r) {
    int ret = 0;
    c-=2;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)ret += seg[c][l++];
        if (r & 1)ret += seg[c][--r];
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i < n; i++){
        int k;
        cin >> k;
        if(k&1) seg[1][n+i]++;
        else seg[0][n+i]++;
    }
    init();
    cin >> q;
    for(int i =0; i < q; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a>=2)cout << query(a,b-1,c) << "\n";
        else{
            update(b-1,c);
        }
    }
}