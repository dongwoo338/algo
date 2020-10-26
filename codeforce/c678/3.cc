#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int n,x,pos;
const int MOD = (int)1e9+7;
ll npr(ll n,ll r){
    ll ret= 1;
    for(ll i = n, j =0 ; j < r; i--, j++)ret=(ret*i)%MOD;
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x >> pos;
    int s= 0, e= n, fn = n;
    int smallc=0,bigc= 0;
    while(s<e){
        fn--;
        int mid =(s+e)/2;
        if(mid < pos){
            s= mid + 1;
            smallc++;
        }
        else if(mid > pos){
            e = mid;
            bigc++;
        }
        else{
            s = mid + 1;
        }
    }
    ll ans= 1;
    ans = (ans * npr(n-x,bigc))%MOD;
    ans = (ans * npr(x-1,smallc))%MOD;
    for(ll i = fn; i >= 1; i--)ans=(ans*i)%MOD;
    cout <<ans%MOD;
}