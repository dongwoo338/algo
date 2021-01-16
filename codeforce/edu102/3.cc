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
        ll n,k;
        cin >> n >> k;
        ll cnt = (n-k)*(n-k+1)/2;
        cout << cnt << "\n";
    }
}