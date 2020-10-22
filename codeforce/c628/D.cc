#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
typedef long double dd;
ll a,b;
ll arr[64];
vector<ll>ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b;
    ll rb= b;
    ll pa= a;
    for(ll i =0; i <= 63; i++){
        if(pa&((ll)1<<i))arr[i]++;
    }
    if(a==0&&b==0){
        cout <<0;
        return 0;
    }
    b -=a;
    if(b<0){
        cout<<-1;
        return 0;
    }
    if(b&(ll)1){
        cout<<-1;
        return 0;
    }
    ll now = ((ll)1<<63);
    while(now>(ll)1){
        if(b>=now){
            ll bb= log2(now>>1);
            arr[bb]+=2;
            b-=now;
        }
        now>>=1;
    }
    dd ldd =0;
    for(ll i=0; i < 64; i++){
        ldd += (dd)((ll)1<<i)*(dd)arr[i];
    }
    if(ldd>rb){
        cout << -1;
        return 0;
    }
    while(1){
        bool isok=0;
        ll tt=0;
        for(ll i=0; i < 64; i++){
            if(arr[i]>0){
                tt += ((ll)1<<i);
                arr[i]--;
                isok=1;
            }
        }
        if(!isok)break;
        ans.push_back(tt);
    }
    cout << ans.size() << "\n";
    for(auto i : ans)cout << i << " ";
}