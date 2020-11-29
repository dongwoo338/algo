#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
const int N = 1<<17;
int seg[2*N][2];//maxval, ind
int n , q;
void update(int s,int val){
    seg[s+N][0]=val; seg[s+N][1]=s;
    s+=N;
    while(s>1){
        int L = seg[s][0];
        int R = seg[s^1][0];
        if(L>=R){
            seg[s>>1][0] = L;
            seg[s>>1][1] = seg[s][1];
        }
        else{
            seg[s>>1][0] = R;
            seg[s>>1][1] = seg[s^1][1];
        }
        s>>=1;
    }
}
pi query(int l, int r) { //[l,r]
    int val = 0, ind = 0;
    r++;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1){
            if(seg[l][0]>val){
                val = seg[l][0];
                ind = seg[l][1];
            }
            l++;
        }
        if (r & 1){
            --r;
            if(seg[r][0]>val){
                val = seg[r][0];
                ind = seg[r][1];
            }
        }
    }    
    return {val,ind};
    cout << "개꿀!!";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i =1; i <= n; i++){
        int k;
        cin >> k;
        update(i,k);
    }
    cin >> q;
    for(int i =0; i < q; i++){
        int qn,s,e;
        cin >> qn >> s >> e;
        if(qn==1){
            update(s,e);
        }
        else{
            auto [val,ind] = query(s,e);
            int an1= val;
            int an2=0;
            if(ind-1>=s)an2 =max(an2,query(s,ind-1).first);
            if(ind+1<=e)an2 =max(an2,query(ind+1,e).first);
            cout << an1 + an2 << "\n";
        }
    }
}