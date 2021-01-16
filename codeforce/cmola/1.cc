#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e9;
typedef pair<int,int> pi;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    ll a,b,c;
    cin >> a >> b >> c;
    ll cnt=1;
    while(a%2==0){
        a/=2;
        cnt<<=1;
    }
    while(b%2==0){
        b/=2;
        cnt<<=1;
    }
    if(cnt>=c)cout<<"YES\n";
    else cout <<"NO\n";
    }
}