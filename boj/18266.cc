#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n,l;
int sums;
int csums;
int ans;
vector<int> pvt; vector<int>mvt;
struct moo{
    int fe,se,te;
    moo(int a,int b,int c):fe(a),se(b),te(c){}
    bool operator<(const moo& M){
        return fe <M.fe;
    }
};
priority_queue<moo> pq;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> l;
    for(int i =0; i < n; i++){
        int w,x,d;
        cin >> w >> x >> d;
        sums += w;
        if(x>=0) pvt.push_back(x);
        else mvt.push_back(x);
        if(d==1)pq.push(moo(x-l,w,x));
        else pq.push(moo(x,-w,x));
    }
    sort(pvt.begin(),pvt.end());
    sort(mvt.begin(),mvt.end());
    while(1){
        auto k = pq.top();
        pq.pop();
        csums += k.se;
        if(csums*2>=sums){
            ans = -k.fe;
            break;
        }
    }
    cout << ans;
}