#include<bits/stdc++.h>
using namespace std;
const int N = 1<<17;
int seg[2*N];
void update(int i){
    for(seg[i+=N]=0; i > 1; i>>=1)seg[i>>1] =seg[i]+seg[i^1];
}
int Q(int l, int r){
    r++;
    int ret=0;
    for(l += N, r+=N; l < r; l >>=1, r>>=1){
        if(l&1)ret += seg[l++];
        if(r&1)ret += seg[--r];
    }
    return ret;
}
int kth(int x){
    int i = 1; 
    while(i < N){
        if(seg[i*2]>=x)i*=2;
        else{
            x-= seg[i*2];
            i = i<<1|1;
        }
    }
    return i - N;
}
vector<int>ans;
int main(){
    int n ,k;
    cin >> n >> k;
    for(int i = 1; i <=n; i++)seg[i+N]=1;
    for(int i = N- 1; i >= 1; i--)seg[i]=seg[i<<1]+seg[i<<1|1];
    int ind =0;
    while(ans.size()<n){
        if(Q(ind,n)<k){
            int nk = k - Q(ind,n);
            ind = kth(nk);
            update(ind);
            ans.push_back(ind);
        }
        else{
            ind = kth(k+Q(1,ind));
            update(ind);
            ans.push_back(ind);
        }
    }
    cout<<'<';
    for(int i =0; i < ans.size()- 1; i++)cout <<ans[i]<<", ";
    cout << ans[n-1];
    cout<<'>';
}